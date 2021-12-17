#ifndef CONFIG_H
#define CONFIG_H

#include "MalfunctionData.h"

#include <list>
#include <string>


#ifndef CHR_TO_STR
	#define CHR_TO_STR(p) std::string(p)
#endif // !CHR_TO_STRING

#ifndef MAX_INPUT_INDEX
	#define MAX_INPUT_INDEX Input::MaxSelectionIndex
#endif

#ifndef MAX_JOBS
	#define	MAX_JOBS Malfunctions::MaxJobs
#endif

#ifndef MAX_TOOLS_INDEX
	#define MAX_TOOLS_INDEX (Tools::MaxTools - 1)
#endif

namespace Input
{
	static const char* ExitKey		= "X";
	static const char* HelpKey		= "H";
	static const char* ConfirmKey	= "Y";
	static const char* CancelKey	= "N";
	static const char* InventoryKey = "I";
	static const char* JobsKey		= "J";
	static const char* AcceptJobKey = "A";
	static const char* ShopKey		= "S";
	static const char* BuyToolKey	= "B";
	static const char* ClearKey		= "C";
	static constexpr int MaxSelectionIndex = 9;
	static const char* Keys[10] = { ExitKey, HelpKey, ConfirmKey, CancelKey, InventoryKey, JobsKey, AcceptJobKey, ShopKey, BuyToolKey, ClearKey };
}

namespace Tools
{
	static constexpr int MaxTools = 6;

	static const char* JackName				= "Jack";
	static const char* TorqueBraceName		= "Torque Brace";
	static const char* JumperCablesName		= "Jumper Cables";
	static const char* PhaseTesterName		= "Phase Tester";
	static const char* HammerName			= "Hammer";
	static const char* ScrewdriverName		= "Screwdriver";
	static const char* ToolsName[MaxTools] = 
	{ JackName, TorqueBraceName, JumperCablesName, PhaseTesterName, HammerName, ScrewdriverName };

	static constexpr int JackPrice			= 50;
	static constexpr int TorqueBracePrice	= 40;
	static constexpr int JumperCablesPrice	= 50;
	static constexpr int PhaseTesterPrice	= 10;
	static constexpr int HammerPrice		= 20;
	static constexpr int ScrewdriverPrice	= 10;
	static constexpr int ToolsPrice[MaxTools] = 
	{ JackPrice, TorqueBracePrice, JumperCablesPrice, PhaseTesterPrice, HammerPrice, ScrewdriverPrice };

	static constexpr int ToolInitialWear = 5;
}

namespace Malfunctions
{
	static constexpr int MaxJobs = 10;

	namespace RacingCar
	{
		static constexpr int MaxMalfunctions = 4;

		static const std::list<const char*> GasPedalBrokenTools = { Tools::ScrewdriverName,	Tools::TorqueBraceName };
		static const std::list<const char*> EngineFailureTools = { Tools::TorqueBraceName, Tools::ScrewdriverName };
		static const std::list<const char*> BaldTireTools = { Tools::JackName,		Tools::TorqueBraceName };
		static const std::list<const char*> BumperDamagedTools = { Tools::HammerName,		Tools::ScrewdriverName };
		static const SMalfunctionData GasPedalBroken = SMalfunctionData( "Gas Pedal Broken",10, GasPedalBrokenTools,EVehicleType::RacingCar );
		static const SMalfunctionData EngineFailure  = SMalfunctionData( "Engine Failure",	10, EngineFailureTools, EVehicleType::RacingCar );
		static const SMalfunctionData BaldTire		 = SMalfunctionData( "Bald Tire",		18, BaldTireTools,		EVehicleType::RacingCar );
		static const SMalfunctionData BumperDamaged  = SMalfunctionData( "Bumped Damaged",	6, BumperDamagedTools,	EVehicleType::RacingCar );
	}
	namespace CompactCar
	{
		static constexpr int MaxMalfunctions = 4;

		static const std::list<const char*> ShockAbsorberTools = { Tools::HammerName,		Tools::ScrewdriverName, Tools::TorqueBraceName };
		static const std::list<const char*> EngineFailureTools = { Tools::TorqueBraceName, Tools::ScrewdriverName };
		static const std::list<const char*> DefectSparkPlugsTools = { Tools::PhaseTesterName, Tools::ScrewdriverName };
		static const std::list<const char*> EmptyBatteryTools = { Tools::JumperCablesName,Tools::PhaseTesterName };
		static const SMalfunctionData ShockAbsorberBroken	= SMalfunctionData( "Shock Absorber Broken",14, ShockAbsorberTools, EVehicleType::CompactCar );
		static const SMalfunctionData EngineFailure			= SMalfunctionData( "Engine Failure",		10, EngineFailureTools, EVehicleType::CompactCar );
		static const SMalfunctionData DefectSparkPlugs		= SMalfunctionData( "Defect Spark Plugs",	4, DefectSparkPlugsTools, EVehicleType::CompactCar );
		static const SMalfunctionData EmptyBattery			= SMalfunctionData( "Empty Battery",		6, EmptyBatteryTools, EVehicleType::CompactCar );
	}
	namespace MotorCycle
	{
		static constexpr int MaxMalfunctions = 3;

		static const std::list<const char*> FlatTireTools = { Tools::JackName,		Tools::TorqueBraceName };
		static const std::list<const char*> EmptyBatteryTools = { Tools::JumperCablesName, Tools::PhaseTesterName };
		static const std::list<const char*> LightsOffTools = { Tools::PhaseTesterName };
		static const SMalfunctionData FlatTire = SMalfunctionData( "Flat Tire", 18, FlatTireTools, EVehicleType::MotorCycle );
		static const SMalfunctionData EmptyBattery = SMalfunctionData( "Empty Battery", 6, EmptyBatteryTools, EVehicleType::MotorCycle );
		static const SMalfunctionData LightsOff = SMalfunctionData( "Lights Off", 2, LightsOffTools, EVehicleType::MotorCycle );
	}

	static constexpr int MaxMalfunctions = 
		Malfunctions::CompactCar::MaxMalfunctions + 
		Malfunctions::RacingCar::MaxMalfunctions + 
		Malfunctions::MotorCycle::MaxMalfunctions;

	static const SMalfunctionData RacingCarMalfunctions[4] = 
	{	Malfunctions::RacingCar::GasPedalBroken, 
		Malfunctions::RacingCar::EngineFailure, 
		Malfunctions::RacingCar::BaldTire, 
		Malfunctions::RacingCar::BumperDamaged };

	static const SMalfunctionData CompactCarMalfunctions[4] =
	{	Malfunctions::CompactCar::ShockAbsorberBroken,
		Malfunctions::CompactCar::EngineFailure,
		Malfunctions::CompactCar::DefectSparkPlugs,
		Malfunctions::CompactCar::EmptyBattery };

	static const SMalfunctionData MotorCycleMalfunctions[3] =
	{	Malfunctions::MotorCycle::FlatTire,
		Malfunctions::MotorCycle::EmptyBattery,
		Malfunctions::MotorCycle::LightsOff };
}

namespace Vehicles
{
	namespace RacingCar
	{
		static const std::list<const char*> Names = { "Ferrari FXX", "Bugatti Veyron", "Ford GT-40", "McLaren F1", "Bugatti Shiron", "Lamborghini Ventador" };
	}
	namespace CompactCar
	{
		static const std::list<const char*> Names = { "Renault Clio", "Toyota Prius", "VW Golf", "Ford Focus", "SEAT Leon", "Renault Megan" };
	}
	namespace MotorCycle
	{
		static const std::list<const char*> Names = { "Kawasaki Ninja", "Honda Rebel", "Honda CBR-125", "Keeway Superlight", "Ducatti Multistrada V4", "Yamaha R1" };
	}
}

namespace PlayerInit
{
	static const char*	FirstStartingToolName	= Tools::JackName;
	static const char*	SecondStartingToolName	= Tools::TorqueBraceName;
	static constexpr int	StartingMoney			= 200;
}

namespace Messages
{
	const std::string ExitComfirmation	= "Are you sure you wish to exit? " + CHR_TO_STR( Input::ConfirmKey ) + " / " + CHR_TO_STR( Input::CancelKey ) + "\n";
	const std::string Welcome			= "Hello Player!\n You are about to lead your own Workshop. \n In order to be successful you should: \n - Keep an eye on your money\n - Always have a set of Tools in your inventory\n - Finish Jobs to earn Money which you can spent in the Hardware shop. \n";
	const std::string Help				= "Press " + 
		CHR_TO_STR( Input::HelpKey ) + 
		" to view all available commands or " + 
		CHR_TO_STR( Input::ExitKey ) + 
		" to quit. \n";
	const std::string Commands = "  '" +
		CHR_TO_STR( Input::InventoryKey ) +
		"'         Inventory: your amount of Money and your available Tools\n  '" +
		CHR_TO_STR( Input::JobsKey ) +
		"'         Jobs: a list of available Jobs\n  '" +
		CHR_TO_STR( Input::AcceptJobKey ) +
		"[index]'  Accept a Job: using the index of the Job list. Example: when typing 'a2' you will accept the Job at index 2\n  '" +
		CHR_TO_STR( Input::ShopKey ) +
		"'         Shop: a list of all available Tools and the Price\n  '" +
		CHR_TO_STR( Input::BuyToolKey ) +
		"[index]'  Buy a Tool: using the index of the Shop list. Example: when typing 'b0' you will buy the first Tool available in the Shop\n  '" +
		CHR_TO_STR( Input::ExitKey ) +
		"'         Quit Game\n  '" +
		CHR_TO_STR( Input::ClearKey ) +
		"'         Clear the console.\n";
	const std::string InputError			= "Error: Invalid input. " + Help;
	const std::string InputErrorNoHelp		= "Error: Invalid input.";
	const std::string AddMoneyCheatEvent	= "Bank error in your favor! Awooooga!\n";
	const std::string UnlockToolsCheatEvent = "Your father gifted you a full set of tools, nice!\n";
}

namespace Cheats
{
	constexpr int Codes = 2;
	const std::string AddMoney = "POTOFGOLD";
	const std::string UnlockTools = "WORKSHOPEMPEROR";
	const std::string All[Codes] = { AddMoney, UnlockTools };
	constexpr int NumMoney = 20000;
}

#endif