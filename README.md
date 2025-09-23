# LyraIntegrationTest
Try to extend Lyra by integrating a simple inventory and ability system

## How to test
1. Add Grid Inventory (https://fab.com/s/13a344fed549) plugin to project.
2. If you get some 'Error: Native pointer usage in member declaration detected', turn off line 16 (NativePointerMemberBehaviorOverride) on LyraEditor.Target.cs: maybe you have some plugin with old-style raw pointer UPROPERTYs, as for me.
3. Add LyraIntegrationTest game feature to any Lyra's existing experience (for example B_ShooterGame_Elimination).
4. Play that experience (for example from level L_ShooterGym).

## Things I learned / things I struggled with
- Using a GameFeature plugin, a special type of plugin designed for the Modular Gameplay Features system, that can be loaded/unloaded at runtime to extend existing experience behavior.
- UChestoryFunctionLibrary::MakeItemDataFromTransfer overrides custom data with its own asset data, so I had to create a Chestory data asset for each lyra item.
- 'Error: Native pointer usage in member declaration detected' (see above) because of my FMOD installed plugin.
- Chestory's InventoryManagerComponent registration issue (see UInventoryManagerFixedComponent::OnComponentCreated() for details).

## Time spent
5 hours - experience and game feature comprehension and setup
2 hours - lyra's itemization framework comprehension
2 hours - inventory system choice and usage test
5 hours - inventory implementation (also struggled with and solved InventoryManagerComponent registration issue)
