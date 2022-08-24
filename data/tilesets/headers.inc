	.align 2
gTileset_General::
	.byte TRUE @ is compressed
	.byte FALSE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_General
	.4byte gTilesetPalettes_General
	.4byte gMetatiles_General
	.4byte gMetatileAttributes_General
	.4byte InitTilesetAnim_General

	.align 2
gTileset_Petalburg::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
  .2byte 3 @ lightPalettes 6,7
	.4byte gTilesetTiles_Petalburg
	.4byte gTilesetPalettes_Petalburg
	.4byte gMetatiles_Petalburg
	.4byte gMetatileAttributes_Petalburg
	.4byte InitTilesetAnim_Petalburg

	.align 2
gTileset_Rustboro::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
  .2byte 1 @ lightPalettes 6
	.4byte gTilesetTiles_Rustboro
	.4byte gTilesetPalettes_Rustboro
	.4byte gMetatiles_Rustboro
	.4byte gMetatileAttributes_Rustboro
	.4byte InitTilesetAnim_Rustboro

	.align 2
gTileset_Dewford::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 64 @ lightPalettes 12
	.4byte gTilesetTiles_Dewford
	.4byte gTilesetPalettes_Dewford
	.4byte gMetatiles_Dewford
	.4byte gMetatileAttributes_Dewford
	.4byte InitTilesetAnim_Dewford

	.align 2
gTileset_Slateport::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
  .2byte 0x41 @ lightPalettes 6,12
	.4byte gTilesetTiles_Slateport
	.4byte gTilesetPalettes_Slateport
	.4byte gMetatiles_Slateport
	.4byte gMetatileAttributes_Slateport
	.4byte InitTilesetAnim_Slateport

	.align 2
gTileset_Mauville::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0x32 @ lightPalettes 7,10,11
	.4byte gTilesetTiles_Mauville
	.4byte gTilesetPalettes_Mauville
	.4byte gMetatiles_Mauville
	.4byte gMetatileAttributes_Mauville
	.4byte InitTilesetAnim_Mauville

	.align 2
gTileset_Lavaridge::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_Lavaridge
	.4byte gTilesetPalettes_Lavaridge
	.4byte gMetatiles_Lavaridge
	.4byte gMetatileAttributes_Lavaridge
	.4byte InitTilesetAnim_Lavaridge

	.align 2
gTileset_Fallarbor::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 2 @ lightPalettes 7
	.4byte gTilesetTiles_Fallarbor
	.4byte gTilesetPalettes_Fallarbor
	.4byte gMetatiles_Fallarbor
	.4byte gMetatileAttributes_Fallarbor
	.4byte InitTilesetAnim_Fallarbor

	.align 2
gTileset_Fortree::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0x0404 @ lightPalettes 8, customLights 8
	.4byte gTilesetTiles_Fortree
	.4byte gTilesetPalettes_Fortree
	.4byte gMetatiles_Fortree
	.4byte gMetatileAttributes_Fortree
	.4byte InitTilesetAnim_Fortree

	.align 2
gTileset_Lilycove::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0x01 @ lightPalettes 6
	.4byte gTilesetTiles_Lilycove
	.4byte gTilesetPalettes_Lilycove
	.4byte gMetatiles_Lilycove
	.4byte gMetatileAttributes_Lilycove
	.4byte InitTilesetAnim_Lilycove

	.align 2
gTileset_Mossdeep::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ lightPalettes 8,9
	.4byte gTilesetTiles_Mossdeep
	.4byte gTilesetPalettes_Mossdeep
	.4byte gMetatiles_Mossdeep
	.4byte gMetatileAttributes_Mossdeep
	.4byte InitTilesetAnim_Mossdeep

	.align 2
gTileset_EverGrande::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_EverGrande
	.4byte gTilesetPalettes_EverGrande
	.4byte gMetatiles_EverGrande
	.4byte gMetatileAttributes_EverGrande
	.4byte InitTilesetAnim_EverGrande

	.align 2
gTileset_Pacifidlog::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 8 @ lightPalettes 9
	.4byte gTilesetTiles_Pacifidlog
	.4byte gTilesetPalettes_Pacifidlog
	.4byte gMetatiles_Pacifidlog
	.4byte gMetatileAttributes_Pacifidlog
	.4byte InitTilesetAnim_Pacifidlog

	.align 2
gTileset_Sootopolis::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0x101 @ lightPalettes 6, customLights 6
	.4byte gTilesetTiles_Sootopolis
	.4byte gTilesetPalettes_Sootopolis
	.4byte gMetatiles_Sootopolis
	.4byte gMetatileAttributes_Sootopolis
	.4byte InitTilesetAnim_Sootopolis

	.align 2
gTileset_BattleFrontierOutsideWest::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_BattleFrontierOutsideWest
	.4byte gTilesetPalettes_BattleFrontierOutsideWest
	.4byte gMetatiles_BattleFrontierOutsideWest
	.4byte gMetatileAttributes_BattleFrontierOutsideWest
	.4byte InitTilesetAnim_BattleFrontierOutsideWest

	.align 2
gTileset_BattleFrontierOutsideEast::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_BattleFrontierOutsideEast
	.4byte gTilesetPalettes_BattleFrontierOutsideEast
	.4byte gMetatiles_BattleFrontierOutsideEast
	.4byte gMetatileAttributes_BattleFrontierOutsideEast
	.4byte InitTilesetAnim_BattleFrontierOutsideEast

	.align 2
gTileset_Building::
	.byte TRUE @ is compressed
	.byte FALSE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_Building
	.4byte gTilesetPalettes_Building
	.4byte gMetatiles_Building
	.4byte gMetatileAttributes_Building
	.4byte 0x0

	.align 2
gTileset_Shop::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_Shop
	.4byte gTilesetPalettes_Shop
	.4byte gMetatiles_Shop
	.4byte gMetatileAttributes_Shop
	.4byte NULL @ animation callback

	.align 2
gTileset_PokemonCenter::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_PokemonCenter
	.4byte gTilesetPalettes_PokemonCenter
	.4byte gMetatiles_PokemonCenter
	.4byte gMetatileAttributes_PokemonCenter
	.4byte NULL @ animation callback

	.align 2
gTileset_Cave::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_Cave
	.4byte gTilesetPalettes_Cave
	.4byte gMetatiles_Cave
	.4byte gMetatileAttributes_Cave
	.4byte NULL

	.align 2
gTileset_PokemonSchool::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_PokemonSchool
	.4byte gTilesetPalettes_PokemonSchool
	.4byte gMetatiles_PokemonSchool
	.4byte gMetatileAttributes_PokemonSchool
	.4byte NULL @ animation callback

	.align 2
gTileset_PokemonFanClub::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_PokemonFanClub
	.4byte gTilesetPalettes_PokemonFanClub
	.4byte gMetatiles_PokemonFanClub
	.4byte gMetatileAttributes_PokemonFanClub
	.4byte NULL @ animation callback

	.align 2
gTileset_Unused1::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_Unused1
	.4byte gTilesetPalettes_Unused1
	.4byte gMetatiles_Unused1
	.4byte gMetatileAttributes_Unused1
	.4byte NULL @ animation callback

	.align 2
gTileset_MeteorFalls::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_MeteorFalls
	.4byte gTilesetPalettes_MeteorFalls
	.4byte gMetatiles_MeteorFalls
	.4byte gMetatileAttributes_MeteorFalls
	.4byte NULL @ animation callback

	.align 2
gTileset_OceanicMuseum::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_OceanicMuseum
	.4byte gTilesetPalettes_OceanicMuseum
	.4byte gMetatiles_OceanicMuseum
	.4byte gMetatileAttributes_OceanicMuseum
	.4byte NULL @ animation callback

	.align 2
gTileset_CableClub::
	.byte FALSE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_CableClub
	.4byte gTilesetPalettes_CableClub
	.4byte gMetatiles_CableClub
	.4byte gMetatileAttributes_CableClub
	.4byte NULL @ animation callback

	.align 2
gTileset_SeashoreHouse::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_SeashoreHouse
	.4byte gTilesetPalettes_SeashoreHouse
	.4byte gMetatiles_SeashoreHouse
	.4byte gMetatileAttributes_SeashoreHouse
	.4byte NULL @ animation callback

	.align 2
gTileset_PrettyPetalFlowerShop::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_PrettyPetalFlowerShop
	.4byte gTilesetPalettes_PrettyPetalFlowerShop
	.4byte gMetatiles_PrettyPetalFlowerShop
	.4byte gMetatileAttributes_PrettyPetalFlowerShop
	.4byte NULL @ animation callback

	.align 2
gTileset_PokemonDayCare::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_PokemonDayCare
	.4byte gTilesetPalettes_PokemonDayCare
	.4byte gMetatiles_PokemonDayCare
	.4byte gMetatileAttributes_PokemonDayCare
	.4byte NULL @ animation callback

	.align 2
gTileset_Facility::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_Facility
	.4byte gTilesetPalettes_Facility
	.4byte gMetatiles_Facility
	.4byte gMetatileAttributes_Facility
	.4byte NULL @ animation callback

	.align 2
gTileset_BikeShop::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_BikeShop
	.4byte gTilesetPalettes_BikeShop
	.4byte gMetatiles_BikeShop
	.4byte gMetatileAttributes_BikeShop
	.4byte NULL

	.align 2
gTileset_RusturfTunnel::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_RusturfTunnel
	.4byte gTilesetPalettes_RusturfTunnel
	.4byte gMetatiles_RusturfTunnel
	.4byte gMetatileAttributes_RusturfTunnel
	.4byte NULL @ animation callback

	.align 2
gTileset_SecretBaseBrownCave::
	.byte FALSE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_SecretBaseBrownCave
	.4byte gTilesetPalettes_SecretBaseBrownCave
	.4byte gMetatiles_SecretBaseSecondary
	.4byte gMetatileAttributes_SecretBaseSecondary
	.4byte NULL @ animation callback

	.align 2
gTileset_SecretBaseTree::
	.byte FALSE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_SecretBaseTree
	.4byte gTilesetPalettes_SecretBaseTree
	.4byte gMetatiles_SecretBaseSecondary
	.4byte gMetatileAttributes_SecretBaseSecondary
	.4byte NULL @ animation callback

	.align 2
gTileset_SecretBaseShrub::
	.byte FALSE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_SecretBaseShrub
	.4byte gTilesetPalettes_SecretBaseShrub
	.4byte gMetatiles_SecretBaseSecondary
	.4byte gMetatileAttributes_SecretBaseSecondary
	.4byte NULL @ animation callback

	.align 2
gTileset_SecretBaseBlueCave::
	.byte FALSE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_SecretBaseBlueCave
	.4byte gTilesetPalettes_SecretBaseBlueCave
	.4byte gMetatiles_SecretBaseSecondary
	.4byte gMetatileAttributes_SecretBaseSecondary
	.4byte NULL @ animation callback

	.align 2
gTileset_SecretBaseYellowCave::
	.byte FALSE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_SecretBaseYellowCave
	.4byte gTilesetPalettes_SecretBaseYellowCave
	.4byte gMetatiles_SecretBaseSecondary
	.4byte gMetatileAttributes_SecretBaseSecondary
	.4byte NULL @ animation callback

	.align 2
gTileset_SecretBaseRedCave::
	.byte FALSE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_SecretBaseRedCave
	.4byte gTilesetPalettes_SecretBaseRedCave
	.4byte gMetatiles_SecretBaseSecondary
	.4byte gMetatileAttributes_SecretBaseSecondary
	.4byte NULL @ animation callback

	.align 2
gTileset_InsideOfTruck::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_InsideOfTruck
	.4byte gTilesetPalettes_InsideOfTruck
	.4byte gMetatiles_InsideOfTruck
	.4byte gMetatileAttributes_InsideOfTruck
	.4byte NULL @ animation callback

	.align 2
gTileset_Unused2::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_Unused2
	.4byte gTilesetPalettes_Unused2
	.4byte gMetatiles_Unused2
	.4byte gMetatileAttributes_Unused2
	.4byte NULL @ animation callback

	.align 2
gTileset_Contest::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_Contest
	.4byte gTilesetPalettes_Contest
	.4byte gMetatiles_Contest
	.4byte gMetatileAttributes_Contest
	.4byte NULL @ animation callback

	.align 2
gTileset_LilycoveMuseum::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_LilycoveMuseum
	.4byte gTilesetPalettes_LilycoveMuseum
	.4byte gMetatiles_LilycoveMuseum
	.4byte gMetatileAttributes_LilycoveMuseum
	.4byte NULL @ animation callback

	.align 2
gTileset_BrendansMaysHouse::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_BrendansMaysHouse
	.4byte gTilesetPalettes_BrendansMaysHouse
	.4byte gMetatiles_BrendansMaysHouse
	.4byte gMetatileAttributes_BrendansMaysHouse
	.4byte NULL @ animation callback

	.align 2
gTileset_Lab::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_Lab
	.4byte gTilesetPalettes_Lab
	.4byte gMetatiles_Lab
	.4byte gMetatileAttributes_Lab
	.4byte NULL @ animation callback

	.align 2
gTileset_Underwater::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_Underwater
	.4byte gTilesetPalettes_Underwater
	.4byte gMetatiles_Underwater
	.4byte gMetatileAttributes_Underwater
	.4byte InitTilesetAnim_Underwater

	.align 2
gTileset_PetalburgGym::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_PetalburgGym
	.4byte gTilesetPalettes_PetalburgGym
	.4byte gMetatiles_PetalburgGym
	.4byte gMetatileAttributes_PetalburgGym
	.4byte NULL @ animation callback

	.align 2
gTileset_SootopolisGym::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_SootopolisGym
	.4byte gTilesetPalettes_SootopolisGym
	.4byte gMetatiles_SootopolisGym
	.4byte gMetatileAttributes_SootopolisGym
	.4byte InitTilesetAnim_SootopolisGym

	.align 2
gTileset_GenericBuilding::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_GenericBuilding
	.4byte gTilesetPalettes_GenericBuilding
	.4byte gMetatiles_GenericBuilding
	.4byte gMetatileAttributes_GenericBuilding
	.4byte NULL @ animation callback

	.align 2
gTileset_MauvilleGameCorner::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_MauvilleGameCorner
	.4byte gTilesetPalettes_MauvilleGameCorner
	.4byte gMetatiles_MauvilleGameCorner
	.4byte gMetatileAttributes_MauvilleGameCorner
	.4byte NULL @ animation callback

	.align 2
gTileset_RustboroGym::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_RustboroGym
	.4byte gTilesetPalettes_RustboroGym
	.4byte gMetatiles_RustboroGym
	.4byte gMetatileAttributes_RustboroGym
	.4byte NULL @ animation callback

	.align 2
gTileset_DewfordGym::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_DewfordGym
	.4byte gTilesetPalettes_DewfordGym
	.4byte gMetatiles_DewfordGym
	.4byte gMetatileAttributes_DewfordGym
	.4byte NULL @ animation callback

	.align 2
gTileset_MauvilleGym::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_MauvilleGym
	.4byte gTilesetPalettes_MauvilleGym
	.4byte gMetatiles_MauvilleGym
	.4byte gMetatileAttributes_MauvilleGym
	.4byte InitTilesetAnim_MauvilleGym

	.align 2
gTileset_LavaridgeGym::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_LavaridgeGym
	.4byte gTilesetPalettes_LavaridgeGym
	.4byte gMetatiles_LavaridgeGym
	.4byte gMetatileAttributes_LavaridgeGym
	.4byte NULL @ animation callback

	.align 2
gTileset_TrickHousePuzzle::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_TrickHousePuzzle
	.4byte gTilesetPalettes_TrickHousePuzzle
	.4byte gMetatiles_TrickHousePuzzle
	.4byte gMetatileAttributes_TrickHousePuzzle
	.4byte NULL @ animation callback

	.align 2
gTileset_FortreeGym::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_FortreeGym
	.4byte gTilesetPalettes_FortreeGym
	.4byte gMetatiles_FortreeGym
	.4byte gMetatileAttributes_FortreeGym
	.4byte NULL @ animation callback

	.align 2
gTileset_MossdeepGym::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_MossdeepGym
	.4byte gTilesetPalettes_MossdeepGym
	.4byte gMetatiles_MossdeepGym
	.4byte gMetatileAttributes_MossdeepGym
	.4byte NULL @ animation callback

	.align 2
gTileset_InsideShip::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_InsideShip
	.4byte gTilesetPalettes_InsideShip
	.4byte gMetatiles_InsideShip
	.4byte gMetatileAttributes_InsideShip
	.4byte NULL @ animation callback

	.align 2
gTileset_SecretBase::
	.byte FALSE @ is compressed
	.byte FALSE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_SecretBase
	.4byte gTilesetPalettes_SecretBase
	.4byte gMetatiles_SecretBasePrimary
	.4byte gMetatileAttributes_SecretBasePrimary
	.4byte NULL @ animation callback

	.align 2
gTilesetPointer_SecretBase::
	.4byte gTileset_SecretBase

	.align 2
gTilesetPointer_SecretBaseRedCave::
	.4byte gTileset_SecretBaseRedCave

	.align 2
gTileset_EliteFour::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_EliteFour
	.4byte gTilesetPalettes_EliteFour
	.4byte gMetatiles_EliteFour
	.4byte gMetatileAttributes_EliteFour
	.4byte InitTilesetAnim_EliteFour

	.align 2
gTileset_BattleFrontier::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_BattleFrontier
	.4byte gTilesetPalettes_BattleFrontier
	.4byte gMetatiles_BattleFrontier
	.4byte gMetatileAttributes_BattleFrontier
	.4byte NULL @ animation callback

	.align 2
gTileset_BattlePalace::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_BattlePalace
	.4byte gTilesetPalettes_BattlePalace
	.4byte gMetatiles_BattlePalace
	.4byte gMetatileAttributes_BattlePalace
	.4byte NULL @ animation callback

	.align 2
gTileset_BattleDome::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_BattleDome
	.4byte gTilesetPalettes_BattleDome
	.4byte gMetatiles_BattleDome
	.4byte gMetatileAttributes_BattleDome
	.4byte InitTilesetAnim_BattleDome

	.align 2
gTileset_BattleFactory::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_BattleFactory
	.4byte gTilesetPalettes_BattleFactory
	.4byte gMetatiles_BattleFactory
	.4byte gMetatileAttributes_BattleFactory
	.4byte NULL @ animation callback

	.align 2
gTileset_BattlePike::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_BattlePike
	.4byte gTilesetPalettes_BattlePike
	.4byte gMetatiles_BattlePike
	.4byte gMetatileAttributes_BattlePike
	.4byte NULL @ animation callback

	.align 2
gTileset_BattleArena::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_BattleArena
	.4byte gTilesetPalettes_BattleArena
	.4byte gMetatiles_BattleArena
	.4byte gMetatileAttributes_BattleArena
	.4byte NULL @ animation callback

	.align 2
gTileset_BattlePyramid::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_BattlePyramid
	.4byte gTilesetPalettes_BattlePyramid
	.4byte gMetatiles_BattlePyramid
	.4byte gMetatileAttributes_BattlePyramid
	.4byte InitTilesetAnim_BattlePyramid

	.align 2
gTileset_MirageTower::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_MirageTower
	.4byte gTilesetPalettes_MirageTower
	.4byte gMetatiles_MirageTower
	.4byte gMetatileAttributes_MirageTower
	.4byte NULL @ animation callback

	.align 2
gTileset_MossdeepGameCorner::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_MossdeepGameCorner
	.4byte gTilesetPalettes_MossdeepGameCorner
	.4byte gMetatiles_MossdeepGameCorner
	.4byte gMetatileAttributes_MossdeepGameCorner
	.4byte NULL @ animation callback

	.align 2
gTileset_IslandHarbor::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_IslandHarbor
	.4byte gTilesetPalettes_IslandHarbor
	.4byte gMetatiles_IslandHarbor
	.4byte gMetatileAttributes_IslandHarbor
	.4byte NULL @ animation callback

	.align 2
gTileset_TrainerHill::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_TrainerHill
	.4byte gTilesetPalettes_TrainerHill
	.4byte gMetatiles_TrainerHill
	.4byte gMetatileAttributes_TrainerHill
	.4byte NULL @ animation callback

	.align 2
gTileset_NavelRock::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_NavelRock
	.4byte gTilesetPalettes_NavelRock
	.4byte gMetatiles_NavelRock
	.4byte gMetatileAttributes_NavelRock
	.4byte NULL @ animation callback

	.align 2
gTileset_BattleFrontierRankingHall::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_BattleFrontierRankingHall
	.4byte gTilesetPalettes_BattleFrontierRankingHall
	.4byte gMetatiles_BattleFrontierRankingHall
	.4byte gMetatileAttributes_BattleFrontierRankingHall
	.4byte NULL @ animation callback

	.align 2
gTileset_BattleTent::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_BattleTent
	.4byte gTilesetPalettes_BattleTent
	.4byte gMetatiles_BattleTent
	.4byte gMetatileAttributes_BattleTent
	.4byte NULL @ animation callback

	.align 2
gTileset_MysteryEventsHouse::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_MysteryEventsHouse
	.4byte gTilesetPalettes_MysteryEventsHouse
	.4byte gMetatiles_MysteryEventsHouse
	.4byte gMetatileAttributes_MysteryEventsHouse
	.4byte NULL @ animation callback

	.align 2
gTileset_UnionRoom::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_UnionRoom
	.4byte gTilesetPalettes_UnionRoom
	.4byte gMetatiles_UnionRoom
	.4byte gMetatileAttributes_UnionRoom
	.4byte NULL @ animation callback

	.align 2
gTileset_PalletTown::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_PalletTown
	.4byte gTilesetPalettes_PalletTown
	.4byte gMetatiles_PalletTown
	.4byte gMetatileAttributes_PalletTown
	.4byte 0x0

	.align 2
gTileset_ViridianCity::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_ViridianCity
	.4byte gTilesetPalettes_ViridianCity
	.4byte gMetatiles_ViridianCity
	.4byte gMetatileAttributes_ViridianCity
	.4byte 0x0

	.align 2
gTileset_PewterCity::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_PewterCity
	.4byte gTilesetPalettes_PewterCity
	.4byte gMetatiles_PewterCity
	.4byte gMetatileAttributes_PewterCity
	.4byte 0x0

	.align 2
gTileset_CeruleanCity::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_CeruleanCity
	.4byte gTilesetPalettes_CeruleanCity
	.4byte gMetatiles_CeruleanCity
	.4byte gMetatileAttributes_CeruleanCity
	.4byte 0x0

	.align 2
gTileset_LavenderTown::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_LavenderTown
	.4byte gTilesetPalettes_LavenderTown
	.4byte gMetatiles_LavenderTown
	.4byte gMetatileAttributes_LavenderTown
	.4byte 0x0

	.align 2
gTileset_VermilionCity::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_VermilionCity
	.4byte gTilesetPalettes_VermilionCity
	.4byte gMetatiles_VermilionCity
	.4byte gMetatileAttributes_VermilionCity
	.4byte 0x0

	.align 2
gTileset_CeladonCity::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_CeladonCity
	.4byte gTilesetPalettes_CeladonCity
	.4byte gMetatiles_CeladonCity
	.4byte gMetatileAttributes_CeladonCity
	.4byte InitTilesetAnim_CeladonCity

	.align 2
gTileset_FuchsiaCity::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_FuchsiaCity
	.4byte gTilesetPalettes_FuchsiaCity
	.4byte gMetatiles_FuchsiaCity
	.4byte gMetatileAttributes_FuchsiaCity
	.4byte 0x0

	.align 2
gTileset_CinnabarIsland::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_CinnabarIsland
	.4byte gTilesetPalettes_CinnabarIsland
	.4byte gMetatiles_CinnabarIsland
	.4byte gMetatileAttributes_CinnabarIsland
	.4byte 0x0

	.align 2
gTileset_IndigoPlateau::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_IndigoPlateau
	.4byte gTilesetPalettes_IndigoPlateau
	.4byte gMetatiles_IndigoPlateau
	.4byte gMetatileAttributes_IndigoPlateau
	.4byte 0x0

	.align 2
gTileset_SaffronCity::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_SaffronCity
	.4byte gTilesetPalettes_SaffronCity
	.4byte gMetatiles_SaffronCity
	.4byte gMetatileAttributes_SaffronCity
	.4byte 0x0

	.align 2
gTileset_Mart::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_Mart
	.4byte gTilesetPalettes_Mart
	.4byte gMetatiles_Mart
	.4byte gMetatileAttributes_Mart
	.4byte 0x0

	.align 2
gTileset_Dummy1::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_Dummy1
	.4byte gTilesetPalettes_Dummy1
	.4byte gMetatiles_Dummy1
	.4byte gMetatileAttributes_Dummy1
	.4byte 0x0

	.align 2
gTileset_Museum::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_Museum
	.4byte gTilesetPalettes_Museum
	.4byte gMetatiles_Museum
	.4byte gMetatileAttributes_Museum
	.4byte 0x0

	.align 2
gTileset_GenericBuilding1::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_GenericBuilding1
	.4byte gTilesetPalettes_GenericBuilding1
	.4byte gMetatiles_GenericBuilding1
	.4byte gMetatileAttributes_GenericBuilding1
	.4byte 0x0

	.align 2
gTileset_FuchsiaGym::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_FuchsiaGym
	.4byte gTilesetPalettes_FuchsiaGym
	.4byte gMetatiles_FuchsiaGym
	.4byte gMetatileAttributes_FuchsiaGym
	.4byte 0x0

	.align 2
gTileset_ViridianGym::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_ViridianGym
	.4byte gTilesetPalettes_ViridianGym
	.4byte gMetatiles_ViridianGym
	.4byte gMetatileAttributes_ViridianGym
	.4byte 0x0

	.align 2
gTileset_HoennBuilding::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_HoennBuilding
	.4byte gTilesetPalettes_HoennBuilding
	.4byte gMetatiles_HoennBuilding
	.4byte gMetatileAttributes_HoennBuilding
	.4byte 0x0

	.align 2
gTileset_GameCorner::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_GameCorner
	.4byte gTilesetPalettes_GameCorner
	.4byte gMetatiles_GameCorner
	.4byte gMetatileAttributes_GameCorner
	.4byte 0x0

	.align 2
gTileset_PewterGym::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_PewterGym
	.4byte gTilesetPalettes_PewterGym
	.4byte gMetatiles_PewterGym
	.4byte gMetatileAttributes_PewterGym
	.4byte 0x0

	.align 2
gTileset_CeruleanGym::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_CeruleanGym
	.4byte gTilesetPalettes_CeruleanGym
	.4byte gMetatiles_CeruleanGym
	.4byte gMetatileAttributes_CeruleanGym
	.4byte 0x0

	.align 2
gTileset_VermilionGym::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_VermilionGym
	.4byte gTilesetPalettes_VermilionGym
	.4byte gMetatiles_VermilionGym
	.4byte gMetatileAttributes_VermilionGym
	.4byte InitTilesetAnim_VermilionGym

	.align 2
gTileset_CeladonGym::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_CeladonGym
	.4byte gTilesetPalettes_CeladonGym
	.4byte gMetatiles_CeladonGym
	.4byte gMetatileAttributes_CeladonGym
	.4byte InitTilesetAnim_CeladonGym

	.align 2
gTileset_SaffronGym::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_SaffronGym
	.4byte gTilesetPalettes_SaffronGym
	.4byte gMetatiles_SaffronGym
	.4byte gMetatileAttributes_SaffronGym
	.4byte 0x0

	.align 2
gTileset_CinnabarGym::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_CinnabarGym
	.4byte gTilesetPalettes_CinnabarGym
	.4byte gMetatiles_CinnabarGym
	.4byte gMetatileAttributes_CinnabarGym
	.4byte 0x0

	.align 2
gTileset_SSAnne::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_SSAnne
	.4byte gTilesetPalettes_SSAnne
	.4byte gMetatiles_SSAnne
	.4byte gMetatileAttributes_SSAnne
	.4byte 0x0

	.align 2
gTileset_Dummy2::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_Dummy2
	.4byte gTilesetPalettes_Dummy2
	.4byte gMetatiles_Dummy2
	.4byte gMetatileAttributes_Dummy2
	.4byte 0x0

	.align 2
gTileset_ViridianForest::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_ViridianForest
	.4byte gTilesetPalettes_ViridianForest
	.4byte gMetatiles_ViridianForest
	.4byte gMetatileAttributes_ViridianForest
	.4byte 0x0

	.align 2
gTileset_UnusedGatehouse1::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_UnusedGatehouse1
	.4byte gTilesetPalettes_UnusedGatehouse1
	.4byte gMetatiles_UnusedGatehouse1
	.4byte gMetatileAttributes_UnusedGatehouse1
	.4byte 0x0

	.align 2
gTileset_RockTunnel::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_RockTunnel
	.4byte gTilesetPalettes_RockTunnel
	.4byte gMetatiles_RockTunnel
	.4byte gMetatileAttributes_RockTunnel
	.4byte 0x0

	.align 2
gTileset_DiglettsCave::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_DiglettsCave
	.4byte gTilesetPalettes_DiglettsCave
	.4byte gMetatiles_DiglettsCave
	.4byte gMetatileAttributes_DiglettsCave
	.4byte 0x0

	.align 2
gTileset_SeafoamIslands::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_SeafoamIslands
	.4byte gTilesetPalettes_SeafoamIslands
	.4byte gMetatiles_SeafoamIslands
	.4byte gMetatileAttributes_SeafoamIslands
	.4byte 0x0

	.align 2
gTileset_UnusedGatehouse2::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_UnusedGatehouse2
	.4byte gTilesetPalettes_UnusedGatehouse2
	.4byte gMetatiles_UnusedGatehouse2
	.4byte gMetatileAttributes_UnusedGatehouse2
	.4byte 0x0

	.align 2
gTileset_CeruleanCave::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_CeruleanCave
	.4byte gTilesetPalettes_CeruleanCave
	.4byte gMetatiles_CeruleanCave
	.4byte gMetatileAttributes_CeruleanCave
	.4byte 0x0

	.align 2
gTileset_DepartmentStore::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_DepartmentStore
	.4byte gTilesetPalettes_DepartmentStore
	.4byte gMetatiles_DepartmentStore
	.4byte gMetatileAttributes_DepartmentStore
	.4byte 0x0

	.align 2
gTileset_GenericBuilding2::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_GenericBuilding2
	.4byte gTilesetPalettes_GenericBuilding2
	.4byte gMetatiles_GenericBuilding2
	.4byte gMetatileAttributes_GenericBuilding2
	.4byte 0x0

	.align 2
gTileset_PowerPlant::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_PowerPlant
	.4byte gTilesetPalettes_PowerPlant
	.4byte gMetatiles_PowerPlant
	.4byte gMetatileAttributes_PowerPlant
	.4byte 0x0

	.align 2
gTileset_SeaCottage::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_SeaCottage
	.4byte gTilesetPalettes_SeaCottage
	.4byte gMetatiles_SeaCottage
	.4byte gMetatileAttributes_SeaCottage
	.4byte 0x0

	.align 2
gTileset_SilphCo::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_SilphCo
	.4byte gTilesetPalettes_SilphCo
	.4byte gMetatiles_SilphCo
	.4byte gMetatileAttributes_SilphCo
	.4byte InitTilesetAnim_SilphCo

	.align 2
gTileset_UndergroundPath::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_UndergroundPath
	.4byte gTilesetPalettes_UndergroundPath
	.4byte gMetatiles_UndergroundPath
	.4byte gMetatileAttributes_UndergroundPath
	.4byte 0x0

	.align 2
gTileset_PokemonTower::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_PokemonTower
	.4byte gTilesetPalettes_PokemonTower
	.4byte gMetatiles_PokemonTower
	.4byte gMetatileAttributes_PokemonTower
	.4byte 0x0

	.align 2
gTileset_SafariZoneBuilding::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_SafariZoneBuilding
	.4byte gTilesetPalettes_SafariZoneBuilding
	.4byte gMetatiles_SafariZoneBuilding
	.4byte gMetatileAttributes_SafariZoneBuilding
	.4byte 0x0

	.align 2
gTileset_PokemonMansion::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_PokemonMansion
	.4byte gTilesetPalettes_PokemonMansion
	.4byte gMetatiles_PokemonMansion
	.4byte gMetatileAttributes_PokemonMansion
	.4byte 0x0

	.align 2
gTileset_RestaurantHotel::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_RestaurantHotel
	.4byte gTilesetPalettes_RestaurantHotel
	.4byte gMetatiles_RestaurantHotel
	.4byte gMetatileAttributes_RestaurantHotel
	.4byte 0x0

	.align 2
gTileset_School::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_School
	.4byte gTilesetPalettes_School
	.4byte gMetatiles_School
	.4byte gMetatileAttributes_School
	.4byte 0x0

	.align 2
gTileset_FanClubDaycare::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_FanClubDaycare
	.4byte gTilesetPalettes_FanClubDaycare
	.4byte gMetatiles_FanClubDaycare
	.4byte gMetatileAttributes_FanClubDaycare
	.4byte 0x0

	.align 2
gTileset_Condominiums::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_SilphCo
	.4byte gTilesetPalettes_SilphCo
	.4byte gMetatiles_Condominiums
	.4byte gMetatileAttributes_Condominiums
	.4byte 0x0

	.align 2
gTileset_BurgledHouse::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_BurgledHouse
	.4byte gTilesetPalettes_BurgledHouse
	.4byte gMetatiles_BurgledHouse
	.4byte gMetatileAttributes_BurgledHouse
	.4byte 0x0

	.align 2
gTileset_Dummy3::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_Dummy3
	.4byte gTilesetPalettes_Dummy3
	.4byte gMetatiles_Dummy3
	.4byte gMetatileAttributes_Dummy3
	.4byte 0x0

	.align 2
gTileset_Dummy4::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_Dummy4
	.4byte gTilesetPalettes_Dummy4
	.4byte gMetatiles_Dummy4
	.4byte gMetatileAttributes_Dummy4
	.4byte 0x0

	.align 2
gTileset_MtEmber::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_MtEmber
	.4byte gTilesetPalettes_MtEmber
	.4byte gMetatiles_MtEmber
	.4byte gMetatileAttributes_MtEmber
	.4byte InitTilesetAnim_MtEmber

	.align 2
gTileset_BerryForest::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_BerryForest
	.4byte gTilesetPalettes_BerryForest
	.4byte gMetatiles_BerryForest
	.4byte gMetatileAttributes_BerryForest
	.4byte 0x0

	.align 2
gTileset_TanobyRuins::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_TanobyRuins
	.4byte gTilesetPalettes_TanobyRuins
	.4byte gMetatiles_TanobyRuins
	.4byte gMetatileAttributes_TanobyRuins
	.4byte 0x0

	.align 2
gTileset_SeviiIslands123::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_SeviiIslands123
	.4byte gTilesetPalettes_SeviiIslands123
	.4byte gMetatiles_SeviiIslands123
	.4byte gMetatileAttributes_SeviiIslands123
	.4byte 0x0

	.align 2
gTileset_SeviiIslands45::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_SeviiIslands45
	.4byte gTilesetPalettes_SeviiIslands45
	.4byte gMetatiles_SeviiIslands45
	.4byte gMetatileAttributes_SeviiIslands45
	.4byte 0x0

	.align 2
gTileset_SeviiIslands67::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_SeviiIslands67
	.4byte gTilesetPalettes_SeviiIslands67
	.4byte gMetatiles_SeviiIslands67
	.4byte gMetatileAttributes_SeviiIslands67
	.4byte 0x0

	.align 2
gTileset_TrainerTower::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_TrainerTower
	.4byte gTilesetPalettes_TrainerTower
	.4byte gMetatiles_TrainerTower
	.4byte gMetatileAttributes_TrainerTower
	.4byte 0x0

	.align 2
gTileset_PokemonLeague::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_PokemonLeague
	.4byte gTilesetPalettes_PokemonLeague
	.4byte gMetatiles_PokemonLeague
	.4byte gMetatileAttributes_PokemonLeague
	.4byte 0x0

	.align 2
gTileset_HallOfFame::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0 @ padding
	.4byte gTilesetTiles_HallOfFame
	.4byte gTilesetPalettes_HallOfFame
	.4byte gMetatiles_HallOfFame
	.4byte gMetatileAttributes_HallOfFame
	.4byte 0x0
