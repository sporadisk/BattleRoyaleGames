/*
    Author - HoverGuy
	Description - Called in fn_buyItem.sqf
	© All Fucks Reserved
*/
params["_item"];
private["_itemClass","_itemType","_itemHandled","_invFull"];

_itemClass = [_item] call HG_fnc_getConfig;
_itemType = getNumber(configFile >> _itemClass >> _item >> "Type");
_itemHandled = true;
_invFull = false;

if(_itemType in [1,2,4]) then
{
    switch(_itemType) do
    {
        case 1: // Primary
        {
            if(primaryWeapon player != "") then
            {
                player removeWeapon (primaryWeapon player);
            };
        };
        case 2: // Handgun
        {
            if(handgunWeapon player != "") then
            {
                player removeWeapon (handgunWeapon player);
            };
        };
        case 4: // Launcher
        {
            if(secondaryWeapon player != "") then
            {
                player removeWeapon (secondaryWeapon player);
            };
        };
    };
	player addWeapon _item;
	player selectWeapon _item;
} else {
	if(_itemType in [16,256,512,768,1536,4096,131072]) then // 16/256/512 = Magazines / 131072 = ItemWatch ItemCompass ItemGPS etc... + Scopes
	{
		private "_canAdd";
		_canAdd = player canAdd _item;
		if(_canAdd) then
		{
			player addItem _item;
		} else {
		    _invFull = true;
		    _itemHandled = false;
		};
    } else {
		_itemHandled = false;
	};
};
	
if(_invFull) then
{
	hint (localize "STR_HG_INVENTORY_FULL");
} else {
    if(!_itemHandled) then 
    {
        hint format[(localize "STR_HG_ITEM_NOT_HANDLED"),getText(configFile >> _itemClass >> _item >> "displayName")];
	};
};

_itemHandled;
