#pragma once

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
