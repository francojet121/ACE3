
class CfgWeapons
{
	class Rifle_Base_F;
	class hlc_MP5_base: Rifle_Base_F
	{
		ACE_barrelTwist=10;
		ACE_barrelLength=9;
	};
	class hlc_smg_mp5k_PDW: hlc_MP5_base
	{
		ACE_barrelTwist=10;
		ACE_barrelLength=4.5;
	};
	class hlc_smg_mp5k: hlc_smg_mp5k_PDW
	{
		ACE_barrelTwist=10;
		ACE_barrelLength=4.5;
	};
	class hlc_smg_mp5a2: hlc_MP5_base
	{
		ACE_barrelTwist=10;
		ACE_barrelLength=9;
	};
	class hlc_smg_MP5N: hlc_MP5_base
	{
		ACE_barrelTwist=10;
		ACE_barrelLength=9;
	};
	class hlc_smg_9mmar: hlc_smg_MP5N
	{
		ACE_barrelTwist=10;
		ACE_barrelLength=9;
	};
	class hlc_smg_mp5a4: hlc_MP5_base
	{
		ACE_barrelTwist=10;
		ACE_barrelLength=9;
	};
	class hlc_smg_mp510: hlc_smg_MP5N
	{
		ACE_barrelTwist=15;
		ACE_barrelLength=9;
	};
	class hlc_smg_mp5sd5: hlc_MP5_base
	{
		ACE_barrelTwist=10;
		ACE_barrelLength=9;
	};
	class hlc_smg_mp5a3: hlc_smg_mp5a2
	{
		ACE_barrelTwist=10;
		ACE_barrelLength=9;
	};
	class hlc_smg_mp5sd6: hlc_smg_mp5sd5
	{
		ACE_barrelTwist=10;
		ACE_barrelLength=9;
    };
};
