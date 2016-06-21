/*
    Author - HoverGuy
	© All Fucks Reserved
*/

/*
    Defines available shops and their content
*/
class HG_VehiclesShopCfg
{
	/* Used as a param for the call, basically the shop you want to display */
	class HG_DefaultShop
	{
		/* Shop type */
        class Civilian
	    {
			/* Shop display name */
	        displayName = "$STR_HG_SHOP_CIVILIAN";
			/* 
			    Shop content 
				0 - STRING - Classname
				1 - INTEGER - Price
			*/
		    vehicles[] =
		    {
		        {"C_SUV_01_F",15000}
		    };
			/* 
			    Spawn pos (markers)
				0 - STRING - Marker display name
				1 - STRING - Marker name
			*/
			spawnPoints[] =
			{
				{"$STR_HG_MARKER_1","civilian_vehicles_spawn"}
			};
	    };
	
	    class Military
	    {
	        displayName = "$STR_HG_SHOP_MILITARY";
		    vehicles[] =
		    {
		        {"B_MRAP_01_F",45000}
		    };
			spawnPoints[] =
			{
				{"$STR_HG_MARKER_2","military_vehicles_spawn"}
			};
	    };
	};
	
	/* 
	----------
	Here you can setup your own shop following the same format as the one just above
	----------
	*/
};

class HG_WeaponsShopCfg
{
	/* Used as a param for the call, basically the shop you want to display */
	class HG_DefaultShop
	{
		/* Shop type */
        class Weapons
	    {
			/* Shop display name */
	        displayName = "$STR_HG_SHOP_WEAPONS";
			/* 
			    Shop content 
				0 - STRING - Classname
				1 - INTEGER - Price
			*/
		    items[] =
		    {
		        {"arifle_MXC_F",12000},
                {"arifle_MXM_F",13000},
                {"hgun_P07_F",1500}
		    };
	    };
	
	    class Items
	    {
	        displayName = "$STR_HG_SHOP_ITEMS";
		    items[] =
		    {
		        {"ItemWatch",50},
			    {"ItemCompass",50},
			    {"ItemGPS",50},
			    {"ItemRadio",50},
			    {"ItemMap",50}
		    };
	    };
	
	    class Magazines
	    {
	        displayName = "$STR_HG_SHOP_MAGAZINES";
		    items[] =
		    {
		        {"30Rnd_65x39_caseless_mag",250},
                {"16Rnd_9x21_Mag",75},
	            {"30Rnd_9x21_Mag",150}
		    };
	    };
	
	    class Scopes
	    {
	        displayName = "$STR_HG_SHOP_SCOPES";
		    items[] =
		    {
		        {"optic_Arco",1000},
			    {"optic_Hamr",1000}
		    };
	    };
	};
	
	/* 
	----------
	Here you can setup your own shop following the same format as the one just above
	----------
	*/
};

class HG_ClothingShopCfg
{
	/* Used as a param for the call, basically the shop you want to display */
	class HG_DefaultShop
	{
		/* Shop type */
		class Facewear
		{
			/* Shop display name */
			displayName = "$STR_HG_SHOP_FACEWEAR";
			/* 
			    Shop type - Used for the camera positioning - MANDATORY
				You can add more camera positions this way (see fn_setCamPos.sqf)
				0 = Headgear / Facewear
				1 = Backpack
				2 = Uniform / Vest
			*/
			type = 0;
			/* 
			    Shop content 
				0 - STRING - Classname
				1 - INTEGER - Price
			*/
			content[] =
			{
				{"G_Balaclava_blk",50},
				{"G_Bandanna_shades",50}
			};
		};
		
		class Headgear
		{
			displayName = "$STR_HG_SHOP_HEADGEAR";
			type = 0;
			content[] =
			{
				{"H_HelmetB_light_grass",1500}
			};
		};
		
		class Vests
	    {
	        displayName = "$STR_HG_SHOP_VESTS";
			type = 2;
		    content[] =
		    {
		        {"V_PlateCarrierGL_mtp",500}
		    };
	    };
		
        class Uniforms
	    {
	        displayName = "$STR_HG_SHOP_UNIFORMS";
			type = 2;
		    content[] =
		    {
		        {"U_B_FullGhillie_ard",150}
		    };
	    };
		
		class Backpacks
		{
			displayName = "$STR_HG_SHOP_BACKPACKS";
			type = 1;
			content[] =
			{
				{"B_Carryall_oucamo",800}
			};
		};
	};
	
	/* 
	----------
	Here you can setup your own shop following the same format as the one just above
	----------
	*/
};
