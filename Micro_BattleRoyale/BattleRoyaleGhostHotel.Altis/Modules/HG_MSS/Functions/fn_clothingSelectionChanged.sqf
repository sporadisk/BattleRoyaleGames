#include "HG_ShopMacros.h"
/*
    Author - HoverGuy
	Description - Called when selection in listbox has changed
	© All Fucks Reserved
*/
params["_ctrl","_index"];

if(_index isEqualTo -1) then
{
    HG_CLOTHING_TEXT ctrlSetStructuredText parseText format
    [
        "<br/>"+
	    " <t align='center' valign='middle' size='1'> "+ (localize "STR_HG_DLG_NO_SELECTION")+ " </t>"
    ]; 
} else {
    private["_item","_price","_itemClass"];
	
	disableSerialization;
	
    _item = _ctrl lbData _index;
    _price = _ctrl lbValue _index;
    _itemClass = [_item] call HG_fnc_getConfig;
	[_item,_price] call HG_fnc_gearPreview;

    HG_CLOTHING_TEXT ctrlSetStructuredText parseText format
    [
        " <br/>"+
		" <img image='%1' size='5' align='center'></img><br/><br/>"+
		" <t align='center' size='1'> "+ (localize "STR_HG_DLG_PRICE_TAG_C")+ " </t>",
		getText(configFile >> _itemClass >> _item >> "picture"),
	    [_price] call BIS_fnc_numberText
    ];
};
