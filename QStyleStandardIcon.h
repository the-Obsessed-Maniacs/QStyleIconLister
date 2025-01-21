#pragma once
/**************************************************************************************************
 * QStyleStandardIcon - a very small helper that mixes Icons together:
 * - there was no "add"-Icon, like a green bullet with a "plus" inside
 * - same about a "remove"-Icon, like a red bullet with a "minus" inside
 *
 * The Qt Standard Pixmaps SP_DialogYesToAllButton and SP_DialogNoToAllButton were left empty in
 * my windows built of Qt.  So these IDs are a good match for the needed Icons.
 *
 * Simply call "StandardIcon::get( QStyle::SP_DialogYesToAllButton )" to get the altered green Plus
 * or use QStyle::SP_DialogNoToAllButton for the remove-icon.  All other standard pixmaps are
 * returned as they are provided by the framework (simple pass-thru).
 *************************************************************************************************/
#include <QStyle>

class StandardIcon
{
  public:
	using StdId = QStyle::StandardPixmap;
	static QIcon get( StdId id );

  private:
	static QIcon build( const QIcon& base, bool plus );
	StandardIcon()	= delete;
	~StandardIcon() = delete;
};
