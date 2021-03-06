/*
 * Copyright (C) 2011-2015 SkyMist Gaming
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * Dungeon: Stormstout Brewery.
 * Description: Instance Script.
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Player.h"
#include "Unit.h"
#include "ObjectAccessor.h"
#include "Group.h"

#include "stormstout_brewery.h"

class instance_stormstout_brewery : public InstanceMapScript
{
    public:
        instance_stormstout_brewery() : InstanceMapScript("instance_stormstout_brewery", 961) { }

        struct instance_stormstout_brewery_InstanceMapScript : public InstanceScript
        {
            instance_stormstout_brewery_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                Initialize();
            }

            // Bosses.
            uint64 uiOokOok;
            uint64 uiHoptallus;
            uint64 uiYanzhuTheUncasked;
            bool OokOokSummoned;
            bool HoptallusSummoned;

            // Hozen killed for Ook-Ook summon.
            uint32 HozenKilled;

            void Initialize()
            {
                SetBossNumber(MAX_ENCOUNTERS);

                // Bosses.
                uiOokOok = 0;
                uiHoptallus = 0;
                uiYanzhuTheUncasked = 0;
                OokOokSummoned = false;
                HoptallusSummoned = false;

                // Hozen killed for Ook-Ook summon.
                HozenKilled = 0;

                for (uint32 i = 0; i < MAX_ENCOUNTERS; ++i)
                    SetBossState(i, NOT_STARTED);
            }

            bool IsEncounterInProgress() const
            {
                for (uint32 i = 0; i < MAX_ENCOUNTERS; ++i)
                    if (GetBossState(i) == IN_PROGRESS)
                        return true;

                return false;
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch(creature->GetEntry())
                {
                    // Bosses.
                    case BOSS_OOKOOK:
                        uiOokOok = creature->GetGUID();
                        break;
                    case BOSS_HOPTALLUS:
                        uiHoptallus = creature->GetGUID();
                        break;
                    case BOSS_YANZHU_THE_UNCASKED:
                        uiYanzhuTheUncasked = creature->GetGUID();
                        break;

                    // NPCs
                    case NPC_ANCESTRAL_BREWMASTER:
                        creature->AddAura(SPELL_ANCESTRAL_BREWM_V, creature);
                        break;

                    default: break;
                }
            }

            void OnUnitDeath(Unit* killed)
            {
                if (killed->GetTypeId() == TYPEID_PLAYER) return;

                switch(killed->ToCreature()->GetEntry())
                {
                    // Script for Ook-ook summon bar.
                    case NPC_SODDEN_HOZEN_BRAWLER:
                    case NPC_INFLAMED_HOZEN_BRAWLER:
                    case NPC_SLEEPY_HOZEN_BRAWLER:
                    case NPC_DRUNKEN_HOZEN_BRAWLER:
                    case NPC_HOZEN_BOUNCER:
                    case NPC_HOZEN_PARTY_ANIMAL:
                        // Increase Hozen killed count.
                        HozenKilled++;
                        // Increase player powers.
                        if (Player* player = killed->FindNearestPlayer(20.0f))
                        {
                            if (player->GetGroup())
                            {
                                if (Player* Leader = ObjectAccessor::FindPlayer(player->GetGroup()->GetLeaderGUID()))
                                {
                                    if (AuraPtr bananas = Leader->GetAura(SPELL_BANANA_BAR))
                                    {
                                        if (HozenKilled < HOZEN_KILLS_NEEDED) // We check the counter in advance to summon Ook-Ook at right value.
                                        {
                                            // Update Leader power.
                                            Leader->SetPower(POWER_ALTERNATE_POWER, HozenKilled);

                                            // Update group members.
                                            for (GroupReference* itr = Leader->GetGroup()->GetFirstMember(); itr != NULL; itr = itr->next())
                                                if (Player* member = itr->getSource())
                                                    if (member != Leader)
                                                        member->SetPower(POWER_ALTERNATE_POWER, HozenKilled);
                                        }
                                        else
                                        {
                                            if (!OokOokSummoned)
                                            {
                                                Leader->SummonCreature(BOSS_OOKOOK, ookOokSummonPosition, TEMPSUMMON_MANUAL_DESPAWN);

                                                // Update group members and remove aura.
                                                for (GroupReference* itr = Leader->GetGroup()->GetFirstMember(); itr != NULL; itr = itr->next())
                                                    if (Player* member = itr->getSource())
                                                        member->RemoveAurasDueToSpell(SPELL_BANANA_BAR);

                                                OokOokSummoned = true;
                                            }
                                        }
                                    }
                                }
                            }
                            else // Solo.
                            {
                                if (AuraPtr bananas = player->GetAura(SPELL_BANANA_BAR))
                                {
                                    if (HozenKilled < HOZEN_KILLS_NEEDED) // We check the counter in advance to summon Ook-Ook at right value.
                                        player->SetPower(POWER_ALTERNATE_POWER, HozenKilled); // // Update player power.
                                    else
                                    {
                                        if (!OokOokSummoned)
                                        {
                                            player->SummonCreature(BOSS_OOKOOK, ookOokSummonPosition, TEMPSUMMON_MANUAL_DESPAWN);
                                            player->RemoveAurasDueToSpell(SPELL_BANANA_BAR);

                                            OokOokSummoned = true;
                                        }
                                    }
                                }
                            }
                        }
                        break;

                        // Script for summoning Hoptallus.
                        case NPC_HOPPER:
                            if (!HoptallusSummoned && killed->GetPositionX() > -707.0f && killed->GetPositionY() < 1280.0f) // Check outside Hopper.
                            {
                                if (Player* player = killed->FindNearestPlayer(20.0f))
                                    player->SummonCreature(BOSS_HOPTALLUS, HoptallusSummonPosition, TEMPSUMMON_MANUAL_DESPAWN);
                                HoptallusSummoned = true;
                            }
                            break;

                    default: break;
                }
            }

            /*
            void OnGameObjectCreate(GameObject* go)
            {
                switch (go->GetEntry())
                {
                }
            }

            void OnGameObjectRemove(GameObject* go)
            {
                switch (go->GetEntry())
                {
                }
            }
            */

            void SetData(uint32 type, uint32 data)
            {
                SetBossState(type, EncounterState(data));

                if (data == DONE)
                    SaveToDB();
            }

            uint32 GetData(uint32 type)
            {
                // First check for type.
                if (type == DATA_HOZEN_KILLED)
                    return HozenKilled;

                return GetBossState(type);
            }

            uint64 GetData64(uint32 data)
            {
                switch(data)
                {
                    // Bosses.
                    case DATA_OOKOOK:               return uiOokOok;             break;
                    case DATA_HOPTALLUS:            return uiHoptallus;          break;
                    case DATA_YANZHU_THE_UNCASKED:  return uiYanzhuTheUncasked;  break;

                    default:                        return 0;                    break;
                }
            }

            bool SetBossState(uint32 data, EncounterState state)
            {
                if (!InstanceScript::SetBossState(data, state))
                    return false;

                if (state == DONE)
                {
                    switch(data)
                    {
                        case DATA_OOKOOK_EVENT:
                        case DATA_HOPTALLUS_EVENT:
                        case DATA_YANZHU_THE_UNCASKED_EVENT:
                        break;
                    }
                }

                return true;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "S B " << GetBossSaveData() << ' ' << HozenKilled;

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(const char* in)
            {
                if (!in)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(in);

                char dataHead1, dataHead2;

                std::istringstream loadStream(in);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'S' && dataHead2 == 'B')
                {
                    for (uint32 i = 0; i < MAX_ENCOUNTERS; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
            
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
            
                        // Below makes the player on-instance-entry display of bosses killed shit work (SMSG_RAID_INSTANCE_INFO).
                        // Like, say an unbound player joins the party and he tries to enter the dungeon / raid.
                        // This makes sure binding-to-instance-on-entrance confirmation box will properly display bosses defeated / available.
                        SetBossState(i, EncounterState(tmpState));

                        // Load killed Hozen counter.
                        uint32 temp = 0;
                        loadStream >> temp;
                        HozenKilled = temp;
                    }
                }
                else OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_stormstout_brewery_InstanceMapScript(map);
        }
};

void AddSC_instance_stormstout_brewery()
{
    new instance_stormstout_brewery();
}
