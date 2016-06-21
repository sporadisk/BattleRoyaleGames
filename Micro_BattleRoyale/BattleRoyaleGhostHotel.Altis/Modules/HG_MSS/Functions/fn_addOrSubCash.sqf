/*
    Author - HoverGuy
	Description - Used to add or substract money from the money variable
	© All Fucks Reserved
*/
params["_amount","_mode"];
private "_oldVal";

_oldVal = player getVariable "HG_myCash";

switch(_mode) do
{
    case 0: 
	{
		player setVariable["HG_myCash",(_oldVal + _amount)];
	};
	case 1:
	{
		player setVariable["HG_myCash",(_oldVal - _amount)];
	};
};
