# Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  Pandaria/boss_sha_of_anger.cpp
  Pandaria/boss_galion.cpp
  Pandaria/boss_nalak.cpp
  Pandaria/boss_chi_ji.cpp
  Pandaria/boss_ordos.cpp

  Pandaria/MogushanPalace/instance_mogu_shan_palace.cpp
  Pandaria/MogushanPalace/boss_trial_of_the_king.cpp
  Pandaria/MogushanPalace/boss_gekkan.cpp
  Pandaria/MogushanPalace/boss_xin_the_weaponmaster.cpp

  Pandaria/TempleJadeSerpent/instance_temple_of_jade_serpent.cpp
  Pandaria/TempleJadeSerpent/boss_wise_mari.cpp
  Pandaria/TempleJadeSerpent/boss_lorewalker_stonestep.cpp
  Pandaria/TempleJadeSerpent/boss_liu_flameheart.cpp
  Pandaria/TempleJadeSerpent/boss_sha_of_doubt.cpp

  Pandaria/StormstoutBrewery/boss_hoptallus.cpp
  Pandaria/StormstoutBrewery/boss_ook_ook.cpp
  Pandaria/StormstoutBrewery/boss_yanzhu_the_uncasked.cpp
  Pandaria/StormstoutBrewery/instance_stormstout_brewery.cpp
  Pandaria/StormstoutBrewery/stormstout_brewery.cpp
  Pandaria/StormstoutBrewery/stormstout_brewery.h

  Pandaria/GateSettingSun/instance_gate_setting_sun.cpp
  Pandaria/GateSettingSun/gate_setting_sun.cpp
  Pandaria/GateSettingSun/gate_setting_sun.h
  Pandaria/GateSettingSun/boss_saboteur_kiptilak.cpp
  Pandaria/GateSettingSun/boss_striker_gadok.cpp
  Pandaria/GateSettingSun/boss_commander_rimok.cpp
  Pandaria/GateSettingSun/boss_raigonn.cpp

  Pandaria/ShadopanMonastery/instance_shadopan_monastery.cpp
  Pandaria/ShadopanMonastery/shadopan_monastery.cpp
  Pandaria/ShadopanMonastery/shadopan_monastery.h
  Pandaria/ShadopanMonastery/boss_gu_cloudstrike.cpp
  Pandaria/ShadopanMonastery/boss_master_snowdrift.cpp
  Pandaria/ShadopanMonastery/boss_sha_of_violence.cpp
  Pandaria/ShadopanMonastery/boss_taran_zhu.cpp
  
  Pandaria/SiegeOfNiuzaoTemple/instance_siege_of_niuzao_temple.cpp
  Pandaria/SiegeOfNiuzaoTemple/siege_of_niuzao_temple.cpp
  Pandaria/SiegeOfNiuzaoTemple/siege_of_niuzao_temple.h
  Pandaria/SiegeOfNiuzaoTemple/boss_vizier_jinbak.cpp
  Pandaria/SiegeOfNiuzaoTemple/boss_general_pavalak.cpp
  Pandaria/SiegeOfNiuzaoTemple/boss_commander_vojak.cpp
  Pandaria/SiegeOfNiuzaoTemple/boss_wing_leader_neronok.cpp

  Pandaria/MogushanVaults/instance_mogu_shan_vaults.cpp
  Pandaria/MogushanVaults/mogu_shan_vaults.cpp
  Pandaria/MogushanVaults/mogu_shan_vaults.h
  Pandaria/MogushanVaults/boss_stone_guard.cpp
  Pandaria/MogushanVaults/boss_feng.cpp
  Pandaria/MogushanVaults/boss_garajal.cpp
  Pandaria/MogushanVaults/boss_spirit_kings.cpp
  Pandaria/MogushanVaults/boss_elegon.cpp
  Pandaria/MogushanVaults/boss_will_of_emperor.cpp

  Pandaria/HeartOfFear/instance_heart_of_fear.cpp
  Pandaria/HeartOfFear/heart_of_fear.cpp
  Pandaria/HeartOfFear/heart_of_fear.h
  Pandaria/HeartOfFear/boss_zorlok.cpp
  Pandaria/HeartOfFear/boss_tayak.cpp
  Pandaria/HeartOfFear/boss_garalon.cpp
  Pandaria/HeartOfFear/boss_meljarak.cpp
  Pandaria/HeartOfFear/boss_unsok.cpp
  Pandaria/HeartOfFear/boss_shekzeer.cpp
  
  Pandaria/TerraceOfEndlessSpring/instance_terrace_of_endless_spring.cpp
  Pandaria/TerraceOfEndlessSpring/terrace_of_endless_spring.cpp
  Pandaria/TerraceOfEndlessSpring/terrace_of_endless_spring.h
  Pandaria/TerraceOfEndlessSpring/boss_protectors_of_the_endless.cpp
  Pandaria/TerraceOfEndlessSpring/boss_tsulong.cpp
  Pandaria/TerraceOfEndlessSpring/boss_lei_shi.cpp
  Pandaria/TerraceOfEndlessSpring/boss_sha_of_fear.cpp

  Pandaria/ToT/instance_throne_of_thunder.cpp
  Pandaria/ToT/throne_of_thunder.h
  Pandaria/ToT/boss_jin_rokh_breaker.cpp
  Pandaria/ToT/boss_horridon.cpp
  Pandaria/ToT/boss_tortos.cpp
  Pandaria/ToT/boss_council_of_elders.cpp
  Pandaria/ToT/boss_megaera.cpp

  Pandaria/SiegeOfOrgrimmar/instance_siege_of_orgrimmar.cpp
  Pandaria/SiegeOfOrgrimmar/siege_of_orgrimmar.cpp
  Pandaria/SiegeOfOrgrimmar/siege_of_orgrimmar.h
  Pandaria/SiegeOfOrgrimmar/boss_immerseus.cpp
  Pandaria/SiegeOfOrgrimmar/boss_fallen_protectors.cpp
  Pandaria/SiegeOfOrgrimmar/boss_norushen.cpp
  Pandaria/SiegeOfOrgrimmar/boss_sha_of_pride.cpp
  Pandaria/SiegeOfOrgrimmar/boss_galakras.cpp
  Pandaria/SiegeOfOrgrimmar/boss_iron_juggernaut.cpp
  Pandaria/SiegeOfOrgrimmar/boss_korkron_dark_shamans.cpp
  Pandaria/SiegeOfOrgrimmar/boss_general_nazgrim.cpp
  Pandaria/SiegeOfOrgrimmar/boss_malkorok.cpp
  Pandaria/SiegeOfOrgrimmar/boss_spoils_of_pandaria.cpp
  Pandaria/SiegeOfOrgrimmar/boss_thok_the_bloodthirsty.cpp
  Pandaria/SiegeOfOrgrimmar/boss_siegecrafter_blackfuse.cpp
  Pandaria/SiegeOfOrgrimmar/boss_paragons_of_the_klaxxi.cpp
  Pandaria/SiegeOfOrgrimmar/boss_garrosh_hellscream.cpp

  Pandaria/WanderingIsland/WanderingIsland_North.cpp
  Pandaria/WanderingIsland/WanderingIsland_East.cpp
  Pandaria/WanderingIsland/WanderingIsland_West.cpp
  Pandaria/WanderingIsland/WanderingIsland_South.cpp

  Pandaria/townlong_steppes.cpp
  Pandaria/dread_wastes.cpp
  Pandaria/valley_of_the_four_winds.cpp
  Pandaria/krasarang_wilds.cpp
  Pandaria/kun_lai_summit.cpp
  Pandaria/jade_forest.cpp
  Pandaria/vale_of_eternal_blossoms.cpp
)

message("  -> Prepared: Pandaria")
