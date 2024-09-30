#include "QStyleStandardIcon.h"

#include <QApplication>
#include <QPainter>
#include <QPen>

QIcon StandardIcon::get( StdId id )
{
	switch ( id )
	{
		case QStyle::SP_DialogYesToAllButton:
			return build( qApp->style()->standardIcon( QStyle::SP_DialogYesButton ), true );
		case QStyle::SP_DialogNoToAllButton:
			return build( qApp->style()->standardIcon( QStyle::SP_DialogNoButton ), false );
		default: return qApp->style()->standardIcon( id );
	}
}

QIcon StandardIcon::build( const QIcon & base, bool plus )
{
	QPainter p;
	QIcon	 res;
	auto	 sizes = base.availableSizes();
	for ( auto sz : sizes )
	{
		for ( auto [ mode, group ] : QList< QPair< QIcon::Mode, QPalette::ColorGroup > >{
				  { QIcon::Normal, QPalette::ColorGroup::Normal },
				  { QIcon::Disabled, QPalette::ColorGroup::Disabled },
				  { QIcon::Active, QPalette::ColorGroup::Active },
				  { QIcon::Selected, QPalette::ColorGroup::Current } } )
		{
			for ( auto state : { QIcon::On, QIcon::Off } )
			{
				auto asz = base.actualSize( sz, mode, state );
				auto pm	 = base.pixmap( asz, mode, state );
				p.begin( &pm );
				QPen p1( p.pen() );
				p1.setCapStyle( Qt::RoundCap );
				QPen p2( p1 );
				p1.setColor( qApp->palette().color( group, QPalette::ColorRole::ButtonText ) );
				p2.setColor( qApp->palette().color( group, QPalette::ColorRole::Shadow ) );
				p1.setWidthF( asz.width() / ( 8. ) );
				p2.setWidthF( asz.width() / ( 16. ) );

				qreal szf = 6;					   // Sizefactor 3
				auto  l	  = 2 * asz.width() / szf; // length of horizontal line => 2/3 width.
				auto  lh  = QLineF( { ( asz.width() - l ) / 2, asz.height() / 2. },
									{ ( asz.width() - l ) / 2 + l, asz.height() / 2. } );
				auto  lv  = QLineF( { asz.width() / 2., ( asz.height() - l ) / 2 },
									{ asz.width() / 2., ( asz.height() - l ) / 2 + l } );
				for ( auto pe : { p1, p2 } )
					p.setPen( pe ), ( plus ? p.drawLines( { lh, lv } ) : p.drawLine( lh ) );
				p.end();
				res.addPixmap( pm, mode, state );
			}
		}
	}
	return res;
}
