#include "QStyleStandardIcon.h"

#include <QApplication>
#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QStyle>
#include <QStyleFactory>
#include <QStyleHints>
#include <QTabWidget>
#include <QToolButton>

const char *strings[] = {
	"SP_TitleBarMenuButton",
	"SP_TitleBarMinButton",
	"SP_TitleBarMaxButton",
	"SP_TitleBarCloseButton",
	"SP_TitleBarNormalButton",
	"SP_TitleBarShadeButton",
	"SP_TitleBarUnshadeButton",
	"SP_TitleBarContextHelpButton",
	"SP_DockWidgetCloseButton",
	"SP_MessageBoxInformation",
	"SP_MessageBoxWarning",
	"SP_MessageBoxCritical",
	"SP_MessageBoxQuestion",
	"SP_DesktopIcon",
	"SP_TrashIcon",
	"SP_ComputerIcon",
	"SP_DriveFDIcon",
	"SP_DriveHDIcon",
	"SP_DriveCDIcon",
	"SP_DriveDVDIcon",
	"SP_DriveNetIcon",
	"SP_DirOpenIcon",
	"SP_DirClosedIcon",
	"SP_DirLinkIcon",
	"SP_DirLinkOpenIcon",
	"SP_FileIcon",
	"SP_FileLinkIcon",
	"SP_ToolBarHorizontalExtensionButton",
	"SP_ToolBarVerticalExtensionButton",
	"SP_FileDialogStart",
	"SP_FileDialogEnd",
	"SP_FileDialogToParent",
	"SP_FileDialogNewFolder",
	"SP_FileDialogDetailedView",
	"SP_FileDialogInfoView",
	"SP_FileDialogContentsView",
	"SP_FileDialogListView",
	"SP_FileDialogBack",
	"SP_DirIcon",
	"SP_DialogOkButton",
	"SP_DialogCancelButton",
	"SP_DialogHelpButton",
	"SP_DialogOpenButton",
	"SP_DialogSaveButton",
	"SP_DialogCloseButton",
	"SP_DialogApplyButton",
	"SP_DialogResetButton",
	"SP_DialogDiscardButton",
	"SP_DialogYesButton",
	"SP_DialogNoButton",
	"SP_ArrowUp",
	"SP_ArrowDown",
	"SP_ArrowLeft",
	"SP_ArrowRight",
	"SP_ArrowBack",
	"SP_ArrowForward",
	"SP_DirHomeIcon",
	"SP_CommandLink",
	"SP_VistaShield",
	"SP_BrowserReload",
	"SP_BrowserStop",
	"SP_MediaPlay",
	"SP_MediaStop",
	"SP_MediaPause",
	"SP_MediaSkipForward",
	"SP_MediaSkipBackward",
	"SP_MediaSeekForward",
	"SP_MediaSeekBackward",
	"SP_MediaVolume",
	"SP_MediaVolumeMuted",
	"SP_LineEditClearButton",
	"SP_DialogYesToAllButton",
	"SP_DialogNoToAllButton",
	"SP_DialogSaveAllButton",
	"SP_DialogAbortButton",
	"SP_DialogRetryButton",
	"SP_DialogIgnoreButton",
	"SP_RestoreDefaultsButton",
	"SP_TabCloseButton",
};

const char *TIs[] = {
	"AddressBookNew",
	"ApplicationExit",
	"AppointmentNew",
	"CallStart",
	"CallStop",
	"ContactNew",
	"DocumentNew",
	"DocumentOpen",
	"DocumentOpenRecent",
	"DocumentPageSetup",
	"DocumentPrint",
	"DocumentPrintPreview",
	"DocumentProperties",
	"DocumentRevert",
	"DocumentSave",
	"DocumentSaveAs",
	"DocumentSend",
	"EditClear",
	"EditCopy",
	"EditCut",
	"EditDelete",
	"EditFind",
	"EditPaste",
	"EditRedo",
	"EditSelectAll",
	"EditUndo",
	"FolderNew",
	"FormatIndentLess",
	"FormatIndentMore",
	"FormatJustifyCenter",
	"FormatJustifyFill",
	"FormatJustifyLeft",
	"FormatJustifyRight",
	"FormatTextDirectionLtr",
	"FormatTextDirectionRtl",
	"FormatTextBold",
	"FormatTextItalic",
	"FormatTextUnderline",
	"FormatTextStrikethrough",
	"GoDown",
	"GoHome",
	"GoNext",
	"GoPrevious",
	"GoUp",
	"HelpAbout",
	"HelpFaq",
	"InsertImage",
	"InsertLink",
	"InsertText",
	"ListAdd",
	"ListRemove",
	"MailForward",
	"MailMarkImportant",
	"MailMarkRead",
	"MailMarkUnread",
	"MailMessageNew",
	"MailReplyAll",
	"MailReplySender",
	"MailSend",
	"MediaEject",
	"MediaPlaybackPause",
	"MediaPlaybackStart",
	"MediaPlaybackStop",
	"MediaRecord",
	"MediaSeekBackward",
	"MediaSeekForward",
	"MediaSkipBackward",
	"MediaSkipForward",
	"ObjectRotateLeft",
	"ObjectRotateRight",
	"ProcessStop",
	"SystemLockScreen",
	"SystemLogOut",
	"SystemSearch",
	"SystemReboot",
	"SystemShutdown",
	"ToolsCheckSpelling",
	"ViewFullscreen",
	"ViewRefresh",
	"ViewRestore",
	"WindowClose",
	"WindowNew",
	"ZoomFitBest",
	"ZoomIn",
	"ZoomOut",
	"AudioCard",
	"AudioInputMicrophone",
	"Battery",
	"CameraPhoto",
	"CameraVideo",
	"CameraWeb",
	"Computer",
	"DriveHarddisk",
	"DriveOptical",
	"InputGaming",
	"InputKeyboard",
	"InputMouse",
	"InputTablet",
	"MediaFlash",
	"MediaOptical",
	"MediaTape",
	"MultimediaPlayer",
	"NetworkWired",
	"NetworkWireless",
	"Phone",
	"Printer",
	"Scanner",
	"VideoDisplay",
	"AppointmentMissed",
	"AppointmentSoon",
	"AudioVolumeHigh",
	"AudioVolumeLow",
	"AudioVolumeMedium",
	"AudioVolumeMuted",
	"BatteryCaution",
	"BatteryLow",
	"DialogError",
	"DialogInformation",
	"DialogPassword",
	"DialogQuestion",
	"DialogWarning",
	"FolderDragAccept",
	"FolderOpen",
	"FolderVisiting",
	"ImageLoading",
	"ImageMissing",
	"MailAttachment",
	"MailUnread",
	"MailRead",
	"MailReplied",
	"MediaPlaylistRepeat",
	"MediaPlaylistShuffle",
	"NetworkOffline",
	"PrinterPrinting",
	"SecurityHigh",
	"SecurityLow",
	"SoftwareUpdateAvailable",
	"SoftwareUpdateUrgent",
	"SyncError",
	"SyncSynchronizing",
	"UserAvailable",
	"UserOffline",
	"WeatherClear",
	"WeatherClearNight",
	"WeatherFewClouds",
	"WeatherFewCloudsNight",
	"WeatherFog",
	"WeatherShowers",
	"WeatherSnow",
	"WeatherStorm",
};

int main( int argc, char *argv[] )
{
	QApplication a( argc, argv );
	QComboBox	*cb = new QComboBox;
	cb->addItems( QStyleFactory::keys() );
	cb->connect( cb, &QComboBox::currentTextChanged,
				 [ &a ]( const QString &text ) { a.setStyle( QStyleFactory::create( text ) ); } );
	QHBoxLayout *hla = new QHBoxLayout;
	hla->addWidget( new QLabel( "Style:" ) );
	hla->addWidget( cb );
	hla->addStretch();
	constexpr const char *ns[] = { "unknown", "bright scheme", "dark scheme" };
	int					  s	   = static_cast< int >( a.styleHints()->colorScheme() );
	hla->addWidget( new QLabel( ns[ s ] ) );
	QVBoxLayout *vla = new QVBoxLayout;
	vla->addLayout( hla );

	auto createSPs = [ & ]()
	{
		QWidget *w	  = new QWidget;
		auto	 gl	  = new QGridLayout();
		auto	 cntx = 5;
		auto	 cnty = qCeil( float( QStyle::NStandardPixmap ) / cntx );
		for ( auto y( 0 ); y < cnty; ++y )
			for ( auto x( 0 ), i( y * cntx ); x < cntx; ++i, ++x )
				if ( i < QStyle::NStandardPixmap )
				{
					auto tb = new QToolButton( w );
					tb->setIconSize( { 32, 32 } );
					tb->setIcon( StandardIcon::get( static_cast< QStyle::StandardPixmap >( i ) ) );
					tb->setText( strings[ i ] );
					tb->setToolButtonStyle( Qt::ToolButtonTextBesideIcon );
					w->connect(
						tb, &QToolButton::clicked,
						[ w, i, tb ]( bool checked )
						{
							auto icon =
								StandardIcon::get( static_cast< QStyle::StandardPixmap >( i ) );
							auto sizes = icon.availableSizes();
							qDebug() << "icon sizes:" << sizes;
							auto l = new QLabel( nullptr, Qt::WindowType::Tool );
							l->setAlignment( Qt::AlignCenter );
							if ( sizes.isEmpty() )
							{
								auto baseIco =
									qApp->style()->standardIcon( QStyle::SP_DialogYesButton );
								QIcon myIcon;
								sizes	 = baseIco.availableSizes();
								auto psz = sizes.last();
								psz		 = { 2 * psz.width(), 4 * psz.height() };
								QPixmap	 pm{ psz };
								QPainter p( &pm );
								for ( auto sz : sizes )
								{
									qDebug() << "build size:" << sz
											 << "actual size:" << baseIco.actualSize( sz );
									auto posy = psz.height() / 8 - ( sz.height() >> 1 );
									for ( auto [ mode, group ] :
										  QList< QPair< QIcon::Mode, QPalette::ColorGroup > >{
											  { QIcon::Normal, QPalette::ColorGroup::Normal },
											  { QIcon::Disabled, QPalette::ColorGroup::Disabled },
											  { QIcon::Active, QPalette::ColorGroup::Active },
											  { QIcon::Selected, QPalette::ColorGroup::Current } } )
									{
										p.drawPixmap( QRect{ QPoint{ 0, posy }, sz },
													  baseIco.pixmap( sz, mode, QIcon::On ) );
										qreal szf = 4;
										QPen  p1( p.pen() );
										p1.setColor( qApp->palette().color(
											group, QPalette::ColorRole::ButtonText ) );
										p1.setCapStyle( Qt::RoundCap );
										QPen p2( p1 );
										p1.setWidthF( sz.width() / ( 10. ) );
										p2.setWidthF( sz.width() / ( 20. ) );
										p2.setColor( qApp->palette().color(
											group, QPalette::ColorRole::Shadow ) );
										auto lns = {
											QLineF( { sz.width() / szf, posy + sz.height() / 2. },
													{ ( szf - 1 ) * sz.width() / szf,
													  posy + sz.height() / 2. } ),
											QLineF( { sz.width() / 2., posy + sz.height() / szf },
													{ sz.width() / 2.,
													  posy + ( szf - 1 ) * sz.height() / szf } ) };
										for ( auto pe : { p1, p2 } )
											p.setPen( pe ), p.drawLines( lns );
										posy += psz.height() / 4;
									}
									p.translate( sz.width(), 0 );
								}
								p.end();
								l->setPixmap( pm );
							} else l->setPixmap( icon.pixmap( sizes.last(), 2. ) );
							l->setWindowTitle( tb->text() );
							l->show();
						} );
					gl->addWidget( tb, y, x );
				} else {
					auto pb = new QPushButton( "only Icons", w );
					pb->setCheckable( true );
					w->connect( pb, &QPushButton::clicked,
								[ w, pb ]( bool checked )
								{
									pb->setText( checked ? "Icons with text" : "only Icons" );
									for ( auto tb : w->findChildren< QToolButton * >() )
										tb->setToolButtonStyle(
											checked ? Qt::ToolButtonIconOnly
													: Qt::ToolButtonTextBesideIcon );
								} );
					gl->addWidget( pb, y, x );
					y = cnty, x = cntx;
				}
		w->setLayout( gl );
		return w;
	};

	auto createTIs = [ & ]()
	{
		auto w	  = new QWidget;
		auto n	  = static_cast< int >( QIcon::ThemeIcon::NThemeIcons );
		auto gl	  = new QGridLayout();
		auto cntx = 5;
		auto cnty = qCeil( float( n ) / cntx );
		for ( auto y( 0 ); y < cnty; ++y )
			for ( auto x( 0 ), i( y * cntx ); x < cntx; ++i, ++x )
				if ( i < n )
				{
					auto tb = new QToolButton( w );
					tb->setIconSize( { 32, 32 } );
					tb->setIcon( QIcon::fromTheme( static_cast< QIcon::ThemeIcon >( i ) ) );
					tb->setText( TIs[ i ] );
					tb->setToolButtonStyle( Qt::ToolButtonTextBesideIcon );
					gl->addWidget( tb, y, x );
				} else {
					auto pb = new QPushButton( "only Icons", w );
					pb->setCheckable( true );
					w->connect( pb, &QPushButton::clicked,
								[ w, pb ]( bool checked )
								{
									pb->setText( checked ? "Icons with text" : "only Icons" );
									for ( auto tb : w->findChildren< QToolButton * >() )
										tb->setToolButtonStyle(
											checked ? Qt::ToolButtonIconOnly
													: Qt::ToolButtonTextBesideIcon );
								} );
					gl->addWidget( pb, y, x );
					y = cnty, x = cntx;
				}
		w->setLayout( gl );
		return w;
	};

	QTabWidget *tw = new QTabWidget;
	tw->setWindowTitle( PROJECT_NAME );
	tw->addTab( createSPs(), "QStyle Standard Pixmaps" );
	tw->addTab( createTIs(), "QIcon::fromTheme" );
	vla->addWidget( tw );
	QWidget w;
	w.setLayout( vla );
	w.show();
	return a.exec();
}
