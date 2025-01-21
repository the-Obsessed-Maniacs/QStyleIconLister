/**************************************************************************************************
 * QStyleIconLister - a small simple program for showing all in-built Icons of Qt.
 * -> using the Qt example "flowlayout" for laying out the buttons.
 *************************************************************************************************/
#include "QStyleStandardIcon.h"
#include "flowlayout.h"

#include <QApplication>
#include <QComboBox>
#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QStyleFactory>
#include <QStyleHints>
#include <QTabWidget>
#include <QToolButton>

// Standard Pixmap strings
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

// Theme Icon strings
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
	QWidget		 w;
	// First, we build a small QStyle-Selector, so the QStyle can be switched
	auto		*cb = new QComboBox;
	cb->addItems( QStyleFactory::keys() );
	cb->connect( cb, &QComboBox::currentTextChanged,
				 [ &a ]( const QString &text ) { a.setStyle( QStyleFactory::create( text ) ); } );
	auto *hla = new QHBoxLayout;
	hla->addWidget( new QLabel( "Style:" ) );
	hla->addWidget( cb );
	hla->addStretch();
	auto pb = new QPushButton( "only Icons" );
	pb->setCheckable( true );
	w.connect( pb, &QPushButton::clicked,
			   [ &w, pb ]( bool checked )
			   {
				   pb->setText( checked ? "Icons with text" : "only Icons" );
				   for ( auto tb : w.findChildren< QToolButton * >() )
					   tb->setToolButtonStyle( checked ? Qt::ToolButtonIconOnly
													   : Qt::ToolButtonTextBesideIcon );
			   } );
	hla->addWidget( pb );
	constexpr const char *ns[] = { "unknown", "bright scheme", "dark scheme" };
	int					  s	   = static_cast< int >( a.styleHints()->colorScheme() );
	hla->addWidget( new QLabel( ns[ s ] ) );
	auto vla = new QVBoxLayout;
	vla->addLayout( hla );

	// Now for the Icon-Listings: with Qt 6.7 Theme Icons were introduced.  Before, there were
	// QStyle::StandardPixmaps - this lambda creates the standard pixmaps tab
	auto createSPs = [ & ]()
	{
		auto w	= new QWidget;
		auto gl = new FlowLayout();
		for ( auto i( 0 ); i < QStyle::NStandardPixmap; ++i )
		{
			auto tb = new QToolButton( w );
			tb->setIconSize( { 32, 32 } );
			tb->setIcon( StandardIcon::get( static_cast< QStyle::StandardPixmap >( i ) ) );
			tb->setText( strings[ i ] );
			tb->setToolButtonStyle( Qt::ToolButtonTextBesideIcon );
			// onClick: open a Window showing the Pixmap in all available sizes
			gl->addWidget( tb );
		}
		w->setLayout( gl );
		return w;
	};
	// Those Theme Icons are new, no need for "open a window to see the icon better"
	auto createTIs = [ & ]()
	{
		auto w	= new QWidget;
		auto n	= static_cast< int >( QIcon::ThemeIcon::NThemeIcons );
		auto gl = new FlowLayout();
		for ( auto i( 0 ); i < n; ++i )
		{
			auto tb = new QToolButton( w );
			tb->setIconSize( { 32, 32 } );
			tb->setIcon( QIcon::fromTheme( static_cast< QIcon::ThemeIcon >( i ) ) );
			tb->setText( TIs[ i ] );
			tb->setToolButtonStyle( Qt::ToolButtonTextBesideIcon );
			gl->addWidget( tb );
		}
		w->setLayout( gl );
		return w;
	};

	// finish the UI
	QTabWidget *tw = new QTabWidget;
	tw->setWindowTitle( PROJECT_NAME );
	tw->addTab( createSPs(), "QStyle Standard Pixmaps" );
	tw->addTab( createTIs(), "QIcon::fromTheme" );
	vla->addWidget( tw );
	w.setLayout( vla );
	w.resize( 800, 600 );
	w.show();
	return a.exec();
}
