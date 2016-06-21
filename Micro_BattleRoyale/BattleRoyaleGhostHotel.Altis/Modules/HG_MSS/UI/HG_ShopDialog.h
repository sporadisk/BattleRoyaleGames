#include "HG_ShopCTS.h"
#include "HG_ShopIDCS.h"
/*
    Author - HoverGuy
	© All Fucks Reserved
*/

/*
    Weapon shop dialog
*/
class HG_WeaponsShopDialog
{
    idd = HG_WEAPONS_SHOP_IDD;
	enableSimulation = true;
	name = "HG_WeaponsShopDialog";
	
	class ControlsBackground
	{
		class Background: HG_RscText
		{
			idc = HG_NO_IDC;
			colorBackground[] = {0,0,0,0.5};
			x = 0.345312 * safezoneW + safezoneX;
		    y = 0.324 * safezoneH + safezoneY;
		    w = 0.309375 * safezoneW;
		    h = 0.418 * safezoneH;
		};
		
		class Header: HG_RscText
		{
			idc = HG_NO_IDC;
			text = "$STR_HG_DLG_TITLE_WEAPONS";
			colorBackground[] = {0.4,0.4,0.4,1};
			x = 0.345312 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.309375 * safezoneW;
			h = 0.055 * safezoneH;
		};
		
		class BackgroundFrame: HG_RscFrame
		{
			idc = HG_NO_IDC;
			x = 0.345312 * safezoneW + safezoneX;
		    y = 0.324 * safezoneH + safezoneY;
		    w = 0.309375 * safezoneW;
		    h = 0.418 * safezoneH;
		};
		
		class TextFrame: HG_RscFrame
		{
			idc = HG_NO_IDC;
			x = 0.510312 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.134062 * safezoneW; 
			h = 0.198 * safezoneH;
		};
		
		class PriceFrame: HG_RscFrame
		{
		    idc = HG_NO_IDC;
			x = 0.510312 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.134062 * safezoneW; 
			h = 0.044 * safezoneH;
		};
		
		class BuyBtnPicture: HG_RscPicture
		{
			idc = HG_NO_IDC;
			text = "HG_MSS\UI\buy.paa";
			x = 0.561875 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
		};
		
		class MyCashBtnPicture: HG_RscPicture
		{
			idc = HG_NO_IDC;
			text = "HG_MSS\UI\mycash.paa";
			x = 0.592812 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
		};
		
		class ExitBtnPicture: HG_RscPicture
		{
			idc = HG_NO_IDC;
			text = "HG_MSS\UI\close.paa";
			x = 0.62375 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
		};
	};
	
	class Controls
	{
	    class ItemList: HG_RscListBox
		{
			idc = HG_WEAPONS_ITEM_LIST_IDC;
			style = "0x02 + 16";
			onLBSelChanged = "_this call HG_fnc_itemSelectionChanged";
			x = 0.355625 * safezoneW + safezoneX;
			y = 0.39 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.33 * safezoneH;
		};
		
		class ItemText: HG_RscStructuredText
		{
			idc = HG_WEAPONS_ITEM_TEXT_IDC;
			colorBackground[] = {0,0,0,0.5};
			x = 0.510312 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.134062 * safezoneW; 
			h = 0.198 * safezoneH;
		};
		
		class ItemPicture: HG_RscPicture
		{
		    idc = HG_WEAPONS_ITEM_PICTURE_IDC;
			x = 0.530937 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.0928125 * safezoneW;
			h = 0.088 * safezoneH;
		};
		
		class ItemPrice: HG_RscText
		{
		    idc = HG_WEAPONS_ITEM_PRICE_IDC;
			style = "0x02";
			colorBackground[] = {0,0,0,0.5};
			x = 0.510312 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.134062 * safezoneW; 
			h = 0.044 * safezoneH;
		};
		
		class ItemSwitch: HG_RscXListBox
		{
		    idc = HG_WEAPONS_ITEM_SWITCH_IDC;
			onLBSelChanged = "_this call HG_fnc_xItemSelectionChanged";
			x = 0.355625 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.022 * safezoneH;
		};
		
		class BuyButton: HG_RscButtonInvisible
		{
			idc = HG_WEAPONS_BUY_IDC;
			tooltip = "$STR_HG_DLG_BUY_W_TOOLTIP";
			onButtonClick = "_this call HG_fnc_buyItem";
			x = 0.561875 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
		};
		
		class MyCashButton: HG_RscButtonInvisible
		{
			idc = HG_WEAPONS_MC_IDC;
			tooltip = "$STR_HG_DLG_MC_TOOLTIP";
			onButtonClick = "hint format[(localize 'STR_HG_DLG_MC'),[(player getVariable 'HG_myCash')] call BIS_fnc_numberText]";
			x = 0.592812 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
		};
		
		class ExitButton: HG_RscButtonInvisible
		{
			idc = HG_NO_IDC;
			tooltip = "$STR_HG_DLG_CLOSE_TOOLTIP";
			onButtonClick = "closeDialog 0";
			x = 0.62375 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
		};
	};
};

/*
    Vehicle shop dialog
*/
class HG_VehiclesShopDialog
{
    idd = HG_VEHICLES_SHOP_IDD;
	enableSimulation = true;
	name = "HG_VehiclesShopDialog";
	onUnload = "_this call HG_fnc_dialogOnUnloadVehicles";
	
	class ControlsBackground
	{
		class ListBackground: HG_RscText
		{
			idc = HG_NO_IDC;
			colorBackground[] = {0,0,0,0.5};
			x = 0.00499997 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.319 * safezoneH;
		};
		
		class SpawnPointsBackground: HG_RscText
		{
			idc = HG_NO_IDC;
			colorBackground[] = {0,0,0,0.5};
			x = 0.850625 * safezoneW + safezoneX;
			y = 0.621 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.044 * safezoneH;
		};
		
		class ListHeader: HG_RscText
		{
			idc = HG_NO_IDC;
			style = "0x02";
			text = "$STR_HG_DLG_TITLE_LIST_VEHICLES";
			colorBackground[] = {0.4,0.4,0.4,1};
			x = 0.00499997 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.033 * safezoneH;
		};
		
		class TextHeader: HG_RscText
		{
			idc = HG_NO_IDC;
			style = "0x02";
			text = "$STR_HG_DLG_TITLE_TEXT_VEHICLES";
			colorBackground[] = {0.4,0.4,0.4,1};
			x = 0.850625 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.033 * safezoneH;
		};
		
		class SpawnPointsHeader: HG_RscText
		{
			idc = HG_NO_IDC;
			style = "0x02";
			text = "$STR_HG_DLG_TITLE_SPAWN_POINTS";
			colorBackground[] = {0.4,0.4,0.4,1};
			x = 0.850625 * safezoneW + safezoneX;
			y = 0.588 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.033 * safezoneH;
		};
		
		class ActionBarBackground: HG_RscText
		{
			idc = HG_NO_IDC;
			text = "$STR_HG_DLG_TITLE_VEHICLES";
			colorBackground[] = {0.4,0.4,0.4,1};
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.00500001 * safezoneH + safezoneY;
			w = 0.4125 * safezoneW;
			h = 0.044 * safezoneH;
		};
		
		class ListBackgroundFrame: HG_RscFrame
		{
			idc = HG_NO_IDC;
			x = 0.00499997 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.319 * safezoneH;
		};
		
		class TextFrame: HG_RscFrame
		{
			idc = HG_NO_IDC;
			x = 0.850625 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.242 * safezoneH;
		};
		
		class SpawnPointsBackgroundFrame: HG_RscFrame
		{
			idc = HG_NO_IDC;
			x = 0.850625 * safezoneW + safezoneX;
			y = 0.621 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.044 * safezoneH;
		};
		
		class BuyBtnPicture: HG_RscPicture
		{
			idc = HG_NO_IDC;
			text = "HG_MSS\UI\buy.paa";
			x = 0.603124 * safezoneW + safezoneX;
			y = 0.00500001 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW; 
			h = 0.044 * safezoneH;
		};
		
		class MyCashBtnPicture: HG_RscPicture
		{
			idc = HG_NO_IDC;
			text = "HG_MSS\UI\mycash.paa";
			x = 0.639218 * safezoneW + safezoneX;
			y = 0.00500001 * safezoneH + safezoneY;
			w = 0.0360937 * safezoneW;
			h = 0.044 * safezoneH;
		};
		
		class ExitBtnPicture: HG_RscPicture
		{
			idc = HG_NO_IDC;
			text = "HG_MSS\UI\close.paa";
			x = 0.675312 * safezoneW + safezoneX;
			y = 0.00500001 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.044 * safezoneH;
		};
	};
	
	class Controls
	{
		class VehicleSwitch: HG_RscXListBox
		{
			idc = HG_VEHICLES_SWITCH_IDC;
			onLBSelChanged = "_this call HG_fnc_xVehicleSelectionChanged";
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.368 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.022 * safezoneH;
		};
		
		class VehicleList: HG_RscListBox
		{
			idc = HG_VEHICLES_LIST_IDC;
			style = "0x02 + 16";
			rowHeight = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			onLBSelChanged = "_this call HG_fnc_vehicleSelectionChanged";
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.401 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.242 * safezoneH;
		};
		
		class VehicleText: HG_RscStructuredText
		{
			idc = HG_VEHICLES_TEXT_IDC;
			colorBackground[] = {0,0,0,0.5};
			x = 0.850625 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.242 * safezoneH;
		};
		
		class SpawnPointsList: HG_RscCombo
		{
			idc = HG_VEHICLES_SP_IDC;
			x = 0.860937 * safezoneW + safezoneX;
			y = 0.632 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.022 * safezoneH;
		};
		
		class BuyButton: HG_RscButtonInvisible
		{
			idc = HG_VEHICLES_BUY_IDC;
			tooltip = "$STR_HG_DLG_BUY_V_TOOLTIP";
			onButtonClick = "_this call HG_fnc_buyVehicle";
			x = 0.603124 * safezoneW + safezoneX;
			y = 0.00500001 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW; 
			h = 0.044 * safezoneH;
		};
		
		class MyCashButton: HG_RscButtonInvisible
		{
			idc = HG_VEHICLES_MC_IDC;
			tooltip = "$STR_HG_DLG_MC_TOOLTIP";
			onButtonClick = "titleText [format[(localize 'STR_HG_DLG_MC'),[(player getVariable 'HG_myCash')] call BIS_fnc_numberText],'PLAIN DOWN',0.5]";
			x = 0.639218 * safezoneW + safezoneX;
			y = 0.00500001 * safezoneH + safezoneY;
			w = 0.0360937 * safezoneW;
			h = 0.044 * safezoneH;
		};
		
		class ExitButton: HG_RscButtonInvisible
		{
			idc = HG_NO_IDC;
			tooltip = "$STR_HG_DLG_CLOSE_TOOLTIP";
			onButtonClick = "closeDialog 0";
			x = 0.675312 * safezoneW + safezoneX;
			y = 0.00500001 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.044 * safezoneH;
		};
	};
};

/*
    Clothing shop dialog
*/
class HG_ClothingShopDialog
{
    idd = HG_CLOTHING_SHOP_IDD;
	enableSimulation = true;
	name = "HG_ClothingShopDialog";
	onUnload = "_this call HG_fnc_dialogOnUnloadClothing";
	
	class ControlsBackground
	{
		class ListBackground: HG_RscText
		{
			idc = HG_NO_IDC;
			colorBackground[] = {0,0,0,0.5};
			x = 0.00499997 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.319 * safezoneH;
		};
		
		class ListHeader: HG_RscText
		{
			idc = HG_NO_IDC;
			style = "0x02";
			text = "$STR_HG_DLG_TITLE_LIST_CLOTHING";
			colorBackground[] = {0.4,0.4,0.4,1};
			x = 0.00499997 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.033 * safezoneH;
		};
		
		class TextHeader: HG_RscText
		{
			idc = HG_NO_IDC;
			style = "0x02";
			text = "$STR_HG_DLG_TITLE_TEXT_CLOTHING";
			colorBackground[] = {0.4,0.4,0.4,1};
			x = 0.850625 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.033 * safezoneH;
		};
		
		class ActionBarBackground: HG_RscText
		{
			idc = HG_NO_IDC;
			text = "$STR_HG_DLG_TITLE_CLOTHING";
			colorBackground[] = {0.4,0.4,0.4,1};
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.00500001 * safezoneH + safezoneY;
			w = 0.4125 * safezoneW;
			h = 0.044 * safezoneH;
		};
		
		class ListBackgroundFrame: HG_RscFrame
		{
			idc = HG_NO_IDC;
			x = 0.00499997 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.319 * safezoneH;
		};
		
		class TextFrame: HG_RscFrame
		{
			idc = HG_NO_IDC;
			x = 0.850625 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.242 * safezoneH;
		};
		
		class ResetBtnPicture: HG_RscPicture
		{
			idc = HG_NO_IDC;
			text = "HG_MSS\UI\reset.paa";
			x = 0.56703 * safezoneW + safezoneX;
			y = 0.00500001 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW; 
			h = 0.044 * safezoneH;
		};
		
		class BuyBtnPicture: HG_RscPicture
		{
			idc = HG_NO_IDC;
			text = "HG_MSS\UI\buy.paa";
			x = 0.603124 * safezoneW + safezoneX;
			y = 0.00500001 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW; 
			h = 0.044 * safezoneH;
		};
		
		class MyCashBtnPicture: HG_RscPicture
		{
			idc = HG_NO_IDC;
			text = "HG_MSS\UI\mycash.paa";
			x = 0.639218 * safezoneW + safezoneX;
			y = 0.00500001 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.044 * safezoneH;
		};
		
		class ExitBtnPicture: HG_RscPicture
		{
			idc = HG_NO_IDC;
			text = "HG_MSS\UI\close.paa";
			x = 0.675312 * safezoneW + safezoneX;
			y = 0.00500001 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.044 * safezoneH;
		};
	};
	
	class Controls
	{
		class ClothingSwitch: HG_RscXListBox
		{
			idc = HG_CLOTHING_SWITCH_IDC;
			onLBSelChanged = "_this call HG_fnc_xClothingSelectionChanged";
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.368 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.022 * safezoneH;
		};
		
		class ClothingList: HG_RscListBox
		{
			idc = HG_CLOTHING_LIST_IDC;
			style = "0x02 + 16";
			rowHeight = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			onLBSelChanged = "_this call HG_fnc_clothingSelectionChanged";
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.401 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.242 * safezoneH;
		};
		
		class ClothingText: HG_RscStructuredText
		{
			idc = HG_CLOTHING_TEXT_IDC;
			colorBackground[] = {0,0,0,0.5};
			x = 0.850625 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.242 * safezoneH;
		};
		
		class ResetButton: HG_RscButtonInvisible
		{
			idc = HG_CLOTHING_RESET_IDC;
			tooltip = "$STR_HG_DLG_RESET_TOOLTIP";
			onButtonClick = "[] call HG_fnc_reset";
			x = 0.56703 * safezoneW + safezoneX;
			y = 0.00500001 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW; 
			h = 0.044 * safezoneH;
		};
		
		class BuyButton: HG_RscButtonInvisible
		{
			idc = HG_CLOTHING_BUY_IDC;
			tooltip = "$STR_HG_DLG_BUY_C_TOOLTIP";
			onButtonClick = "_this call HG_fnc_buyClothing";
			x = 0.603124 * safezoneW + safezoneX;
			y = 0.00500001 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW; 
			h = 0.044 * safezoneH;
		};
		
		class MyCashButton: HG_RscButtonInvisible
		{
			idc = HG_CLOTHING_MC_IDC;
			tooltip = "$STR_HG_DLG_MC_TOOLTIP";
			onButtonClick = "titleText [format[(localize 'STR_HG_DLG_MC'),[(player getVariable 'HG_myCash')] call BIS_fnc_numberText],'PLAIN DOWN',0.5]";
			x = 0.639218 * safezoneW + safezoneX;
			y = 0.00500001 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.044 * safezoneH;
		};
		
		class ExitButton: HG_RscButtonInvisible
		{
			idc = HG_NO_IDC;
			tooltip = "$STR_HG_DLG_CLOSE_TOOLTIP";
			onButtonClick = "closeDialog 0";
			x = 0.675312 * safezoneW + safezoneX;
			y = 0.00500001 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.044 * safezoneH;
		};
	};
};
