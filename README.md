# LyraIntegrationTest
Try to extend Lyra by integrating a simple inventory and ability system

## How to test
1. Clone this project in the Plugins\GameFeatures folder of your Lyra project.
2. Add the Chestory Inventory System (https://www.fab.com/it/listings/f354ae92-6be2-4898-980e-c13e28a55e85) plugin to project.
3. If you get some 'Error: Native pointer usage in member declaration detected', turn off line 16 (NativePointerMemberBehaviorOverride) on LyraEditor.Target.cs: maybe you have some plugin with old-style raw pointer UPROPERTYs, as for me.
4. Add LyraIntegrationTest game feature to Lyra's B_ShooterGame_Elimination experience.
5. Play that experience from test level LyraIntegrationTest\Maps\L_IntegrationTest.

## Things I learned / things I struggled with
- Using a GameFeature plugin, a special type of plugin designed for the Modular Gameplay Features system, that can be loaded/unloaded at runtime to extend existing experience behavior.
- UChestoryFunctionLibrary::MakeItemDataFromTransfer overrides custom data with its own asset data, so I had to create a Chestory data asset for each lyra item.
- 'Error: Native pointer usage in member declaration detected' (see above) because of my FMOD installed plugin.
- Chestory's InventoryManagerComponent registration issue (see UInventoryManagerFixedComponent::OnComponentCreated() for details).
- GameFeature plugins can depend from each other! This allow me to use ShooterCore base functionalities in GameFeature plugin and extend them!
- LyraAbilitySets can grant abilities, effects and even attribute sets for you, avoiding a lot of boilerplate!

## Time spent
5 hours - experience and game feature comprehension and setup
2 hours - lyra's itemization framework comprehension
2 hours - inventory system choice and usage test
5 hours - inventory implementation (also struggled with and solved Chestory's InventoryManagerComponent registration issue)
3 hours - implement B_EquipmentSpawner and equippable items
1 hour - application of helmet's game effect
2 hours - implementation of the healing belt item, with related ability and healing game effect

## Design a Server-Authoritative Item System

- All items live on the server. The client can ask to pick something up, move it, or equip it, but the server decides if that’s valid and only then updates the item.
- There are items definitions (how an item is done) and item instances with their own state and an unique GUID (placed on world on in the player's inventory).
- The server keeps track of inventories (both world chests or pickups and players owned) in its own database.
- When a match starts, the player's selected equipment is "frozen" temporarily in the server owned player's inventory.
- When a match ends:
	- if the player survived, he get all its current items, that will be placed in it's own inventory.
	- if the player died, frozen equipment is deleted from server and the player lose it.
