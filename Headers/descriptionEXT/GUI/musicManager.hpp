#include "musicManagerCommonDefines.hpp"
#define PROFILE_BACKGROUND_COLOR(ALPHA)\
{\
	"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",\
	"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",\
	"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",\
	ALPHA\
}
#define BORDER_COLOR(ALPHA) {0,0,0,ALPHA}
#define BACKGROUND_FRAME_COLOR(ALPHA) {0,0,0,ALPHA}
#define GREY_COLOR(PERCENT,ALPHA) {PERCENT,PERCENT,PERCENT,ALPHA}

//missionconfigfile >> "musicManagerDialog"
/* -------------------------------------------------------------------------
	Base Classes
------------------------------------------------------------------------- */




/* -------------------------------------------------------------------------
	Dialog
------------------------------------------------------------------------- */
class musicManagerDialog
{
	idd = BLWK_MUSIC_MANAGER_IDD;
	enableSimulation = true;
	onLoad = "_this call BLWK_fnc_musicManagerOnLoad";

	class controlsBackground
	{
		class musicManagerDialogbackground_frame: RscText
		{
			idc = -1;
			x = 0.253906 * safezoneW + safezoneX;
			y = 0.25 * safezoneH + safezoneY;
			w = 0.492188 * safezoneW;
			h = 0.53125 * safezoneH;
			colorBackground[] = GREY_COLOR(0.24,0.7);
		};
		class musicManagerDialogbackground_filler_1: RscText
		{
			idc = -1;
			x = 0.552734 * safezoneW + safezoneX;
			y = 0.416667 * safezoneH + safezoneY;
			w = 0.0117188 * safezoneW;
			h = 0.114583 * safezoneH;
			colorBackground[] = {-1,-1,-1,1};
		};
		class musicManagerDialogbackground_filler_2: RscText
		{
			idc = -1;
			x = 0.552734 * safezoneW + safezoneX;
			y = 0.59375 * safezoneH + safezoneY;
			w = 0.0117188 * safezoneW;
			h = 0.15625 * safezoneH;
			colorBackground[] = {-1,-1,-1,1};
		};
		class musicManagerDialogbackground_filler_3: RscText
		{
			idc = -1;
			x = 0.552734 * safezoneW + safezoneX;
			y = 0.552083 * safezoneH + safezoneY;
			w = 0.0117188 * safezoneW;
			h = 0.0208333 * safezoneH;
			colorBackground[] = {-1,-1,-1,1};
		};
		class musicManagerDialogbackground_filler_4: RscText
		{
			idc = -1;
			text = "";
			x = 0.259766 * safezoneW + safezoneX;
			y = 0.75 * safezoneH + safezoneY;
			w = 0.480469 * safezoneW;
			h = 0.0208333 * safezoneH;
			colorBackground[] = {-1,-1,-1,1};
		};
	};
	
	class controls
	{
		class musicManagerDialoglistBox_currentPlaylist: RscListBox
		{
			idc = BLWK_MUSIC_MANAGER_CURRENT_PLAYLIST_IDC;

			x = 0.564453 * safezoneW + safezoneX;
			y = 0.416667 * safezoneH + safezoneY;
			w = 0.175781 * safezoneW;
			h = 0.333333 * safezoneH;
			colorBackground[] = GREY_COLOR(0,1);
			sizeEx = 0.0208333 * safezoneH;
		};
		class musicManagerDialoglistNBox_availableSongs: RscListNBox
		{
			idc = BLWK_MUSIC_MANAGER_SONGS_LIST_IDC;
			//onLoad = "[(_this select 0)] call loadMusic";

			x = 0.259766 * safezoneW + safezoneX;
			y = 0.416667 * safezoneH + safezoneY;
			w = 0.292969 * safezoneW;
			h = 0.333333 * safezoneH;
			colorBackground[] = GREY_COLOR(0.24,1);
			sizeEx = 0.0208333 * safezoneH;
		};
		class musicManagerDialogheaderText_musicManager: RscText
		{
			idc = -1;
			text = "Music Manager"; //--- ToDo: Localize;
			x = 0.253906 * safezoneW + safezoneX;
			y = 0.229167 * safezoneH + safezoneY;
			w = 0.427734 * safezoneW;
			h = 0.0208333 * safezoneH;
			colorBackground[] = PROFILE_BACKGROUND_COLOR(1);
		};
		class musicManagerDialogbutton_closeDialog: RscButton
		{
			idc = BLWK_MUSIC_MANAGER_CLOSE_BUTTON_IDC;

			text = "Close"; //--- ToDo: Localize;
			x = 0.681641 * safezoneW + safezoneX;
			y = 0.229167 * safezoneH + safezoneY;
			w = 0.0644531 * safezoneW;
			h = 0.0208333 * safezoneH;
		};
		class musicManagerDialogbutton_commit: RscButton
		{
			idc = BLWK_MUSIC_MANAGER_COMMIT_BUTTON_IDC;

			text = "Commit Playlist To Server"; //--- ToDo: Localize;
			x = 0.634766 * safezoneW + safezoneX;
			y = 0.28125 * safezoneH + safezoneY;
			w = 0.105469 * safezoneW;
			h = 0.0416667 * safezoneH;
		};
		class musicManagerDialogslider_timeline: RscXSliderH
		{
			idc = BLWK_MUSIC_MANAGER_TIMELINE_SLIDER_IDC;

			x = 0.242187 * safezoneW + safezoneX;
			y = 0.364583 * safezoneH + safezoneY;
			w = 0.515625 * safezoneW;
			h = 0.03125 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.25};
			sliderStep = 0.01;
			lineSize = 0;
		};
		class musicManagerDialogbutton_play: RscButton
		{
			idc = BLWK_MUSIC_MANAGER_PLAY_BUTTON_IDC;
			text = "Play"; //--- ToDo: Localize;
			x = 0.652344 * safezoneW + safezoneX;
			y = 0.333333 * safezoneH + safezoneY;
			w = 0.0527344 * safezoneW;
			h = 0.0208333 * safezoneH;
		};
		class musicManagerDialogbutton_pause: RscButton
		{
			idc = BLWK_MUSIC_MANAGER_PAUSE_BUTTON_IDC;
			text = "Pause"; //--- ToDo: Localize;
			x = 0.294922 * safezoneW + safezoneX;
			y = 0.333333 * safezoneH + safezoneY;
			w = 0.0527344 * safezoneW;
			h = 0.0208333 * safezoneH;
		};
		class musicManagerDialogheaderText_currentPlaylist: RscText
		{
			idc = -1;

			text = "Current Playlist"; //--- ToDo: Localize;
			x = 0.564453 * safezoneW + safezoneX;
			y = 0.395833 * safezoneH + safezoneY;
			w = 0.175781 * safezoneW;
			h = 0.0208333 * safezoneH;
			colorBackground[] = PROFILE_BACKGROUND_COLOR(1);
		};
		class musicManagerDialogheaderText_volume: RscText
		{
			idc = -1;

			text = "Volume:"; //--- ToDo: Localize;
			x = 0.435547 * safezoneW + safezoneX;
			y = 0.333333 * safezoneH + safezoneY;
			w = 0.0351563 * safezoneW;
			h = 0.0208333 * safezoneH;
			colorBackground[] = PROFILE_BACKGROUND_COLOR(1);
		};
		class musicManagerDialogslider_volume: RscXSliderH
		{
			idc = BLWK_MUSIC_MANAGER_VOLUME_SLIDER_IDC;

			x = 0.458984 * safezoneW + safezoneX;
			y = 0.333333 * safezoneH + safezoneY;
			w = 0.123047 * safezoneW;
			h = 0.0208333 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.25};
			sliderStep = 0.05;
			sliderRange = [0,1];
			lineSize = 0;
		};
		class musicManagerDialogheaderText_trackTitle: RscText
		{
			idc = -1;

			text = "Track Title"; //--- ToDo: Localize;
			x = 0.259766 * safezoneW + safezoneX;
			y = 0.395833 * safezoneH + safezoneY;
			w = 0.240234 * safezoneW;
			h = 0.0208333 * safezoneH;
			colorBackground[] = PROFILE_BACKGROUND_COLOR(1);
		};
		class musicManagerDialogheaderText_duration: RscText
		{
			idc = -1;

			text = "Duration"; //--- ToDo: Localize;
			x = 0.5 * safezoneW + safezoneX;
			y = 0.395833 * safezoneH + safezoneY;
			w = 0.0644531 * safezoneW;
			h = 0.0208333 * safezoneH;
			colorBackground[] = PROFILE_BACKGROUND_COLOR(1);
		};
		class musicManagerDialogedit_trackSpacing: RscEdit
		{
			idc = BLWK_MUSIC_MANAGER_SPACING_EDIT_IDC;

			//text = "[200,250,300]"; //--- ToDo: Localize;
			x = 0.306641 * safezoneW + safezoneX;
			y = 0.302083 * safezoneH + safezoneY;
			w = 0.0585937 * safezoneW;
			h = 0.0208333 * safezoneH;
			colorBackground[] = GREY_COLOR(1,0.25);
			
		};
		class musicManagerDialogbutton_trackSpacing: RscButton
		{
			idc = BLWK_MUSIC_MANAGER_SPACING_BUTTON_IDC;

			text = "Set Spacing"; //--- ToDo: Localize;
			x = 0.259766 * safezoneW + safezoneX;
			y = 0.302083 * safezoneH + safezoneY;
			w = 0.046875 * safezoneW;
			h = 0.0208333 * safezoneH;
			colorBackground[] = {-1,-1,-1,1};
			toolTip = "Setting will be saved to the server";
		};
		class musicManagerDialogcomboBox_trackSpacing: RscCombo
		{
			idc = BLWK_MUSIC_MANAGER_SPACING_COMBO_IDC;

			x = 0.259766 * safezoneW + safezoneX;
			y = 0.28125 * safezoneH + safezoneY;
			w = 0.105469 * safezoneW;
			h = 0.0208333 * safezoneH;
		};
		class musicManagerDialogcomboBox_systemOnOff: RscCombo
		{
			idc = BLWK_MUSIC_MANAGER_ONOFF_COMBO_IDC;

			x = 0.634766 * safezoneW + safezoneX;
			y = 0.260417 * safezoneH + safezoneY;
			w = 0.105469 * safezoneW;
			h = 0.0208333 * safezoneH;
		};
		class musicManagerDialogedit_savePlaylist: RscEdit
		{
			idc = BLWK_MUSIC_MANAGER_SAVE_EDIT_IDC;

			text = "A Playlist name"; //--- ToDo: Localize;
			x = 0.5 * safezoneW + safezoneX;
			y = 0.291667 * safezoneH + safezoneY;
			w = 0.105469 * safezoneW;
			h = 0.0208333 * safezoneH;
			colorBackground[] = GREY_COLOR(1,0.25);
		};
		class musicManagerDialogcomboBox_loadPlaylist: RscCombo
		{
			idc = BLWK_MUSIC_MANAGER_LOAD_COMBO_IDC;

			x = 0.394531 * safezoneW + safezoneX;
			y = 0.291667 * safezoneH + safezoneY;
			w = 0.105469 * safezoneW;
			h = 0.0208333 * safezoneH;
		};
		class musicManagerDialogheaderText_trackSpacing: RscText
		{
			idc = -1;
			text = "Track Spacing"; //--- ToDo: Localize;
			x = 0.259766 * safezoneW + safezoneX;
			y = 0.260417 * safezoneH + safezoneY;
			w = 0.105469 * safezoneW;
			h = 0.0208333 * safezoneH;
			colorBackground[] = PROFILE_BACKGROUND_COLOR(1);
		};
		class musicManagerDialogbutton_savePlaylist: RscButton
		{
			idc = BLWK_MUSIC_MANAGER_SAVE_BUTTON_IDC;

			text = "Save"; //--- ToDo: Localize;
			x = 0.552734 * safezoneW + safezoneX;
			y = 0.270833 * safezoneH + safezoneY;
			w = 0.0527344 * safezoneW;
			h = 0.0208333 * safezoneH;
			toolTip = "Save over the current list selected in the drop down";
			//colorBackground[] = {-1,-1,-1,1};
		};
		class musicManagerDialogbutton_saveAsPlaylist: RscButton
		{
			idc = BLWK_MUSIC_MANAGER_SAVEAS_BUTTON_IDC;

			text = "Save As"; //--- ToDo: Localize;
			x = 0.5 * safezoneW + safezoneX;
			y = 0.270833 * safezoneH + safezoneY;
			w = 0.0527344 * safezoneW;
			h = 0.0208333 * safezoneH;
			toolTip = "Save a new playlist based upon the edit box";
			//colorBackground[] = {-1,-1,-1,1};
		};
		class musicManagerDialogbutton_deletePlaylist: RscButton
		{
			idc = BLWK_MUSIC_MANAGER_DELETE_BUTTON_IDC;

			text = "Delete"; //--- ToDo: Localize;
			x = 0.394531 * safezoneW + safezoneX;
			y = 0.270833 * safezoneH + safezoneY;
			w = 0.0292969 * safezoneW;
			h = 0.0208333 * safezoneH;
			toolTip = "Delete the currently selected list in the drop down";
			//colorBackground[] = {-1,-1,-1,1};
		};
		class musicManagerDialogheaderText_loadPlaylist: RscText
		{
			idc = -1;
			text = "Load Playlist"; //--- ToDo: Localize;
			x = 0.423828 * safezoneW + safezoneX;
			y = 0.270833 * safezoneH + safezoneY;
			w = 0.0761719 * safezoneW;
			h = 0.0208333 * safezoneH;
			colorBackground[] = PROFILE_BACKGROUND_COLOR(1);
		};
		
		class musicManagerDialogbutton_addToCurrentPlaylist: RscButton
		{
			idc = BLWK_MUSIC_MANAGER_ADDTO_BUTTON_IDC;

			text = "+"; //--- ToDo: Localize;
			x = 0.552734 * safezoneW + safezoneX;
			y = 0.53125 * safezoneH + safezoneY;
			w = 0.0117188 * safezoneW;
			h = 0.0208333 * safezoneH;

			toolTip = "Add to Current Playlist";
		};
		class musicManagerDialogbutton_removeFromCurrentPlaylist: RscButton
		{
			idc = BLWK_MUSIC_MANAGER_REMOVEFROM_BUTTON_IDC;

			text = "-"; //--- ToDo: Localize;
			x = 0.552734 * safezoneW + safezoneX;
			y = 0.572917 * safezoneH + safezoneY;
			w = 0.0117188 * safezoneW;
			h = 0.0208333 * safezoneH;

			toolTip = "Remove from Current Playlist";
		};
	};
};