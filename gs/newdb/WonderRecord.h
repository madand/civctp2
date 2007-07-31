
/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */
#ifndef __Wonder_RECORD_H__
#define __Wonder_RECORD_H__

/*
 * Wonder description
 */
#include "CTPRecord.h"
//
// m_flags0
#define k_Wonder_ReduceReadinessCost_Bit         0x00000001
#define k_Wonder_EmbassiesEverywhere_Bit         0x00000002
#define k_Wonder_DecCrimePercent_Bit             0x00000004
#define k_Wonder_IncKnowledgePercent_Bit         0x00000008
#define k_Wonder_DecEmpireSize_Bit               0x00000010
#define k_Wonder_IncHappinessEmpire_Bit          0x00000020
#define k_Wonder_CloseEmbassies_Bit              0x00000040
#define k_Wonder_ReformCities_Bit                0x00000080
#define k_Wonder_FreeSlaves_Bit                  0x00000100
#define k_Wonder_IncConvertedCitiesFeePercent_Bit 0x00000200
#define k_Wonder_GoldPerWaterTradeRoute_Bit      0x00000400
#define k_Wonder_GoldPerTelevision_Bit           0x00000800
#define k_Wonder_GlobalRadar_Bit                 0x00001000
#define k_Wonder_SpiesEverywhere_Bit             0x00002000
#define k_Wonder_GoldPerInternationalTradeRoute_Bit 0x00004000
#define k_Wonder_ProtectFromBiologicalWarfare_Bit 0x00008000
#define k_Wonder_PollutersToParks_Bit            0x00010000
#define k_Wonder_EnableParkRangers_Bit           0x00020000
#define k_Wonder_ReduceWorldPollution_Bit        0x00040000
#define k_Wonder_AllCitizensContent_Bit          0x00080000
#define k_Wonder_EliminateNukes_Bit              0x00100000
#define k_Wonder_AllBoatsDeepWater_Bit           0x00200000
#define k_Wonder_IncreaseBoatMovement_Bit        0x00400000
#define k_Wonder_FreeTradeRoutes_Bit             0x00800000
#define k_Wonder_DecreaseMaintenance_Bit         0x01000000
#define k_Wonder_RandomAdvanceChance_Bit         0x02000000
#define k_Wonder_IncreaseHp_Bit                  0x04000000
#define k_Wonder_MultiplyTradeRoutes_Bit         0x08000000
#define k_Wonder_ForcefieldEverywhere_Bit        0x10000000
#define k_Wonder_IncreaseScientists_Bit          0x20000000
#define k_Wonder_OtherCivRandomAdvanceChance_Bit 0x40000000
#define k_Wonder_IncreaseProduction_Bit          0x80000000
//
// m_flags1
#define k_Wonder_BonusGold_Bit                   0x00000001
#define k_Wonder_IncreaseFoodAllCities_Bit       0x00000002
#define k_Wonder_TemporaryFullHappiness_Bit      0x00000004
#define k_Wonder_RevoltingCitiesJoinPlayer_Bit   0x00000008
#define k_Wonder_NoPollutionUnhappiness_Bit      0x00000010
#define k_Wonder_EmbassiesEverywhereEvenAtWar_Bit 0x00000020
#define k_Wonder_IncreaseSpecialists_Bit         0x00000040
#define k_Wonder_IncreaseCathedrals_Bit          0x00000080
#define k_Wonder_IncreaseBrokerages_Bit          0x00000100
#define k_Wonder_IncreaseRegard_Bit              0x00000200
#define k_Wonder_PreventConversion_Bit           0x00000400
#define k_Wonder_ProtectFromBarbarians_Bit       0x00000800
#define k_Wonder_StartGaiaController_Bit         0x00001000
#define k_Wonder_GLHidden_Bit                    0x00002000
#define k_Wonder_BuildingEverywhere_Bit          0x00004000
#define k_Wonder_PollutionPercent_Bit            0x00008000
#define k_Wonder_PollutionAmount_Bit             0x00010000
//
// Range definitions
#define k_MAX_ObsoleteAdvance                5

/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */
class IconRecord;
class WonderMovieRecord;
class AdvanceRecord;
class AdvanceRecord;
class BuildingRecord;

class WonderRecord : public CTPRecord
{
public:
    typedef sint32 (WonderRecord::*IntAccessor)() const;
    typedef bool (WonderRecord::*BoolAccessor)() const;
    typedef double (WonderRecord::*FloatAccessor)() const ;
    typedef bool (WonderRecord::*BitIntAccessor)(sint32 &val) const;
    typedef bool (WonderRecord::*BitFloatAccessor)(double &val) const;
private:
    uint32 m_flags0;
    uint32 m_flags1;

    sint32            m_ProductionCost;
    sint32            m_DefaultIcon; // Index into Icon database
    sint32            m_Movie; // Index into WonderMovie database
    sint32            m_Description;
    sint32            m_EnableAdvance; // Index into Advance database
    sint32            m_ObsoleteAdvance[k_MAX_ObsoleteAdvance]; // Index into Advance database
    sint32           m_numObsoleteAdvance;
    sint32            m_ReduceReadinessCostValue;
    sint32            m_DecCrimePercentValue;
    sint32            m_IncKnowledgePercentValue;
    sint32            m_DecEmpireSizeValue;
    sint32            m_IncHappinessEmpireValue;
    sint32            m_IncConvertedCitiesFeePercentValue;
    sint32            m_GoldPerWaterTradeRouteValue;
    sint32            m_GoldPerTelevisionValue;
    sint32            m_GoldPerInternationalTradeRouteValue;
    sint32            m_PollutersToParksValue;
    sint32            m_ReduceWorldPollutionValue;
    sint32            m_IncreaseBoatMovementValue;
    sint32            m_DecreaseMaintenanceValue;
    sint32            m_RandomAdvanceChanceValue;
    sint32            m_IncreaseHpValue;
    sint32            m_MultiplyTradeRoutesValue;
    sint32            m_IncreaseScientistsValue;
    sint32            m_OtherCivRandomAdvanceChanceValue;
    sint32            m_IncreaseProductionValue;
    sint32            m_BonusGoldValue;
    sint32            m_IncreaseFoodAllCitiesValue;
    sint32            m_TemporaryFullHappinessValue;
    sint32            m_IncreaseSpecialistsValue;
    sint32            m_IncreaseCathedralsValue;
    sint32            m_IncreaseBrokeragesValue;
    sint32            m_IncreaseRegardValue;
    sint32            m_BuildingEverywhereValue; // Index into Building database
    double            m_PollutionPercentValue;
    double            m_PollutionAmountValue;

public:
    WonderRecord() { Init(); };
    ~WonderRecord();
    Init();
    // These methods are needed for records to conform to
    // 'Orthodox Cannonical Form' and work with resizing STL vectors. 
    WonderRecord(const WonderRecord &rval) { Init(); *this = rval; }
    void operator=(const WonderRecord &rval);

    void CheckRequiredFields(DBLexer *lex);
    sint32 Parse(DBLexer *lex);

    void ResolveDBReferences();
    void Merge(const WonderRecord & rval);
    //
    // Accessors
    //
    sint32           GetProductionCost() const { return m_ProductionCost; }
    sint32           GetDefaultIconIndex() const { return m_DefaultIcon; }
    const IconRecord *GetDefaultIcon() const;
    sint32           GetMovieIndex() const { return m_Movie; }
    const WonderMovieRecord *GetMovie() const;
    sint32           GetDescription() const { return m_Description; }
    sint32           GetEnableAdvanceIndex() const { return m_EnableAdvance; }
    const AdvanceRecord *GetEnableAdvance() const;
    sint32           GetObsoleteAdvanceIndex(sint32 index) const;
    const AdvanceRecord *GetObsoleteAdvance(sint32 index) const;
    sint32           GetNumObsoleteAdvance() const { return m_numObsoleteAdvance;}
    bool             GetReduceReadinessCost() const { return (m_flags0 & k_Wonder_ReduceReadinessCost_Bit) != 0; }
    bool             GetReduceReadinessCost(sint32 &value) const {
                         if((m_flags0 & k_Wonder_ReduceReadinessCost_Bit) == 0) return false;
                         value = m_ReduceReadinessCostValue;
                         return true;
                     }
    bool             GetEmbassiesEverywhere() const { return (m_flags0 & k_Wonder_EmbassiesEverywhere_Bit) != 0; }
    bool             GetDecCrimePercent() const { return (m_flags0 & k_Wonder_DecCrimePercent_Bit) != 0; }
    bool             GetDecCrimePercent(sint32 &value) const {
                         if((m_flags0 & k_Wonder_DecCrimePercent_Bit) == 0) return false;
                         value = m_DecCrimePercentValue;
                         return true;
                     }
    bool             GetIncKnowledgePercent() const { return (m_flags0 & k_Wonder_IncKnowledgePercent_Bit) != 0; }
    bool             GetIncKnowledgePercent(sint32 &value) const {
                         if((m_flags0 & k_Wonder_IncKnowledgePercent_Bit) == 0) return false;
                         value = m_IncKnowledgePercentValue;
                         return true;
                     }
    bool             GetDecEmpireSize() const { return (m_flags0 & k_Wonder_DecEmpireSize_Bit) != 0; }
    bool             GetDecEmpireSize(sint32 &value) const {
                         if((m_flags0 & k_Wonder_DecEmpireSize_Bit) == 0) return false;
                         value = m_DecEmpireSizeValue;
                         return true;
                     }
    bool             GetIncHappinessEmpire() const { return (m_flags0 & k_Wonder_IncHappinessEmpire_Bit) != 0; }
    bool             GetIncHappinessEmpire(sint32 &value) const {
                         if((m_flags0 & k_Wonder_IncHappinessEmpire_Bit) == 0) return false;
                         value = m_IncHappinessEmpireValue;
                         return true;
                     }
    bool             GetCloseEmbassies() const { return (m_flags0 & k_Wonder_CloseEmbassies_Bit) != 0; }
    bool             GetReformCities() const { return (m_flags0 & k_Wonder_ReformCities_Bit) != 0; }
    bool             GetFreeSlaves() const { return (m_flags0 & k_Wonder_FreeSlaves_Bit) != 0; }
    bool             GetIncConvertedCitiesFeePercent() const { return (m_flags0 & k_Wonder_IncConvertedCitiesFeePercent_Bit) != 0; }
    bool             GetIncConvertedCitiesFeePercent(sint32 &value) const {
                         if((m_flags0 & k_Wonder_IncConvertedCitiesFeePercent_Bit) == 0) return false;
                         value = m_IncConvertedCitiesFeePercentValue;
                         return true;
                     }
    bool             GetGoldPerWaterTradeRoute() const { return (m_flags0 & k_Wonder_GoldPerWaterTradeRoute_Bit) != 0; }
    bool             GetGoldPerWaterTradeRoute(sint32 &value) const {
                         if((m_flags0 & k_Wonder_GoldPerWaterTradeRoute_Bit) == 0) return false;
                         value = m_GoldPerWaterTradeRouteValue;
                         return true;
                     }
    bool             GetGoldPerTelevision() const { return (m_flags0 & k_Wonder_GoldPerTelevision_Bit) != 0; }
    bool             GetGoldPerTelevision(sint32 &value) const {
                         if((m_flags0 & k_Wonder_GoldPerTelevision_Bit) == 0) return false;
                         value = m_GoldPerTelevisionValue;
                         return true;
                     }
    bool             GetGlobalRadar() const { return (m_flags0 & k_Wonder_GlobalRadar_Bit) != 0; }
    bool             GetSpiesEverywhere() const { return (m_flags0 & k_Wonder_SpiesEverywhere_Bit) != 0; }
    bool             GetGoldPerInternationalTradeRoute() const { return (m_flags0 & k_Wonder_GoldPerInternationalTradeRoute_Bit) != 0; }
    bool             GetGoldPerInternationalTradeRoute(sint32 &value) const {
                         if((m_flags0 & k_Wonder_GoldPerInternationalTradeRoute_Bit) == 0) return false;
                         value = m_GoldPerInternationalTradeRouteValue;
                         return true;
                     }
    bool             GetProtectFromBiologicalWarfare() const { return (m_flags0 & k_Wonder_ProtectFromBiologicalWarfare_Bit) != 0; }
    bool             GetPollutersToParks() const { return (m_flags0 & k_Wonder_PollutersToParks_Bit) != 0; }
    bool             GetPollutersToParks(sint32 &value) const {
                         if((m_flags0 & k_Wonder_PollutersToParks_Bit) == 0) return false;
                         value = m_PollutersToParksValue;
                         return true;
                     }
    bool             GetEnableParkRangers() const { return (m_flags0 & k_Wonder_EnableParkRangers_Bit) != 0; }
    bool             GetReduceWorldPollution() const { return (m_flags0 & k_Wonder_ReduceWorldPollution_Bit) != 0; }
    bool             GetReduceWorldPollution(sint32 &value) const {
                         if((m_flags0 & k_Wonder_ReduceWorldPollution_Bit) == 0) return false;
                         value = m_ReduceWorldPollutionValue;
                         return true;
                     }
    bool             GetAllCitizensContent() const { return (m_flags0 & k_Wonder_AllCitizensContent_Bit) != 0; }
    bool             GetEliminateNukes() const { return (m_flags0 & k_Wonder_EliminateNukes_Bit) != 0; }
    bool             GetAllBoatsDeepWater() const { return (m_flags0 & k_Wonder_AllBoatsDeepWater_Bit) != 0; }
    bool             GetIncreaseBoatMovement() const { return (m_flags0 & k_Wonder_IncreaseBoatMovement_Bit) != 0; }
    bool             GetIncreaseBoatMovement(sint32 &value) const {
                         if((m_flags0 & k_Wonder_IncreaseBoatMovement_Bit) == 0) return false;
                         value = m_IncreaseBoatMovementValue;
                         return true;
                     }
    bool             GetFreeTradeRoutes() const { return (m_flags0 & k_Wonder_FreeTradeRoutes_Bit) != 0; }
    bool             GetDecreaseMaintenance() const { return (m_flags0 & k_Wonder_DecreaseMaintenance_Bit) != 0; }
    bool             GetDecreaseMaintenance(sint32 &value) const {
                         if((m_flags0 & k_Wonder_DecreaseMaintenance_Bit) == 0) return false;
                         value = m_DecreaseMaintenanceValue;
                         return true;
                     }
    bool             GetRandomAdvanceChance() const { return (m_flags0 & k_Wonder_RandomAdvanceChance_Bit) != 0; }
    bool             GetRandomAdvanceChance(sint32 &value) const {
                         if((m_flags0 & k_Wonder_RandomAdvanceChance_Bit) == 0) return false;
                         value = m_RandomAdvanceChanceValue;
                         return true;
                     }
    bool             GetIncreaseHp() const { return (m_flags0 & k_Wonder_IncreaseHp_Bit) != 0; }
    bool             GetIncreaseHp(sint32 &value) const {
                         if((m_flags0 & k_Wonder_IncreaseHp_Bit) == 0) return false;
                         value = m_IncreaseHpValue;
                         return true;
                     }
    bool             GetMultiplyTradeRoutes() const { return (m_flags0 & k_Wonder_MultiplyTradeRoutes_Bit) != 0; }
    bool             GetMultiplyTradeRoutes(sint32 &value) const {
                         if((m_flags0 & k_Wonder_MultiplyTradeRoutes_Bit) == 0) return false;
                         value = m_MultiplyTradeRoutesValue;
                         return true;
                     }
    bool             GetForcefieldEverywhere() const { return (m_flags0 & k_Wonder_ForcefieldEverywhere_Bit) != 0; }
    bool             GetIncreaseScientists() const { return (m_flags0 & k_Wonder_IncreaseScientists_Bit) != 0; }
    bool             GetIncreaseScientists(sint32 &value) const {
                         if((m_flags0 & k_Wonder_IncreaseScientists_Bit) == 0) return false;
                         value = m_IncreaseScientistsValue;
                         return true;
                     }
    bool             GetOtherCivRandomAdvanceChance() const { return (m_flags0 & k_Wonder_OtherCivRandomAdvanceChance_Bit) != 0; }
    bool             GetOtherCivRandomAdvanceChance(sint32 &value) const {
                         if((m_flags0 & k_Wonder_OtherCivRandomAdvanceChance_Bit) == 0) return false;
                         value = m_OtherCivRandomAdvanceChanceValue;
                         return true;
                     }
    bool             GetIncreaseProduction() const { return (m_flags0 & k_Wonder_IncreaseProduction_Bit) != 0; }
    bool             GetIncreaseProduction(sint32 &value) const {
                         if((m_flags0 & k_Wonder_IncreaseProduction_Bit) == 0) return false;
                         value = m_IncreaseProductionValue;
                         return true;
                     }
    bool             GetBonusGold() const { return (m_flags1 & k_Wonder_BonusGold_Bit) != 0; }
    bool             GetBonusGold(sint32 &value) const {
                         if((m_flags1 & k_Wonder_BonusGold_Bit) == 0) return false;
                         value = m_BonusGoldValue;
                         return true;
                     }
    bool             GetIncreaseFoodAllCities() const { return (m_flags1 & k_Wonder_IncreaseFoodAllCities_Bit) != 0; }
    bool             GetIncreaseFoodAllCities(sint32 &value) const {
                         if((m_flags1 & k_Wonder_IncreaseFoodAllCities_Bit) == 0) return false;
                         value = m_IncreaseFoodAllCitiesValue;
                         return true;
                     }
    bool             GetTemporaryFullHappiness() const { return (m_flags1 & k_Wonder_TemporaryFullHappiness_Bit) != 0; }
    bool             GetTemporaryFullHappiness(sint32 &value) const {
                         if((m_flags1 & k_Wonder_TemporaryFullHappiness_Bit) == 0) return false;
                         value = m_TemporaryFullHappinessValue;
                         return true;
                     }
    bool             GetRevoltingCitiesJoinPlayer() const { return (m_flags1 & k_Wonder_RevoltingCitiesJoinPlayer_Bit) != 0; }
    bool             GetNoPollutionUnhappiness() const { return (m_flags1 & k_Wonder_NoPollutionUnhappiness_Bit) != 0; }
    bool             GetEmbassiesEverywhereEvenAtWar() const { return (m_flags1 & k_Wonder_EmbassiesEverywhereEvenAtWar_Bit) != 0; }
    bool             GetIncreaseSpecialists() const { return (m_flags1 & k_Wonder_IncreaseSpecialists_Bit) != 0; }
    bool             GetIncreaseSpecialists(sint32 &value) const {
                         if((m_flags1 & k_Wonder_IncreaseSpecialists_Bit) == 0) return false;
                         value = m_IncreaseSpecialistsValue;
                         return true;
                     }
    bool             GetIncreaseCathedrals() const { return (m_flags1 & k_Wonder_IncreaseCathedrals_Bit) != 0; }
    bool             GetIncreaseCathedrals(sint32 &value) const {
                         if((m_flags1 & k_Wonder_IncreaseCathedrals_Bit) == 0) return false;
                         value = m_IncreaseCathedralsValue;
                         return true;
                     }
    bool             GetIncreaseBrokerages() const { return (m_flags1 & k_Wonder_IncreaseBrokerages_Bit) != 0; }
    bool             GetIncreaseBrokerages(sint32 &value) const {
                         if((m_flags1 & k_Wonder_IncreaseBrokerages_Bit) == 0) return false;
                         value = m_IncreaseBrokeragesValue;
                         return true;
                     }
    bool             GetIncreaseRegard() const { return (m_flags1 & k_Wonder_IncreaseRegard_Bit) != 0; }
    bool             GetIncreaseRegard(sint32 &value) const {
                         if((m_flags1 & k_Wonder_IncreaseRegard_Bit) == 0) return false;
                         value = m_IncreaseRegardValue;
                         return true;
                     }
    bool             GetPreventConversion() const { return (m_flags1 & k_Wonder_PreventConversion_Bit) != 0; }
    bool             GetProtectFromBarbarians() const { return (m_flags1 & k_Wonder_ProtectFromBarbarians_Bit) != 0; }
    bool             GetStartGaiaController() const { return (m_flags1 & k_Wonder_StartGaiaController_Bit) != 0; }
    bool             GetGLHidden() const { return (m_flags1 & k_Wonder_GLHidden_Bit) != 0; }
    bool             GetBuildingEverywhere() const { return (m_flags1 & k_Wonder_BuildingEverywhere_Bit) != 0; }
    bool             GetBuildingEverywhereIndex(sint32 &index) const {
                         if((m_flags1 & k_Wonder_BuildingEverywhere_Bit) == 0) return false;
                         index = m_BuildingEverywhereValue;
                         return true;
                     }
    bool             GetBuildingEverywhere(const BuildingRecord *&rec) const;
    const BuildingRecord  *GetBuildingEverywherePtr() const;
    bool             GetPollutionPercent() const { return (m_flags1 & k_Wonder_PollutionPercent_Bit) != 0; }
    bool             GetPollutionPercent(double &value) const {
                         if((m_flags1 & k_Wonder_PollutionPercent_Bit) == 0) return false;
                         value = m_PollutionPercentValue;
                         return true;
                     }
    bool             GetPollutionAmount() const { return (m_flags1 & k_Wonder_PollutionAmount_Bit) != 0; }
    bool             GetPollutionAmount(double &value) const {
                         if((m_flags1 & k_Wonder_PollutionAmount_Bit) == 0) return false;
                         value = m_PollutionAmountValue;
                         return true;
                     }
}; /* WonderRecord */

struct WonderRecordAccessorInfo {
    WonderRecord::IntAccessor m_intAccessor;
    WonderRecord::BoolAccessor m_boolAccessor;
    WonderRecord::FloatAccessor m_floatAccessor;
    WonderRecord::BitIntAccessor m_bitIntAccessor;
    WonderRecord::BitFloatAccessor m_bitFloatAccessor;
};
extern WonderRecordAccessorInfo g_WonderRecord_Accessors[];
extern char *g_Wonder_Tokens[];
#define k_Num_WonderRecord_Tokens 84

template <class T> class CTPDatabase;
extern CTPDatabase<WonderRecord> *g_theWonderDB;

#endif /* ifndef __Wonder_RECORD_H__ */
