======== INSTALLATION ========

This mod requires the ndmodloader (https://www.nexusmods.com/thelastofuspart2/mods/32).

Simply put the more_resources.psarc file in your mods folder.

If you have other mods installed that edit the "player-inventory.bin" file and you're experiencing issues, please let me know.

The optional section below requires ndarc (https://www.nexusmods.com/thelastofuspart2/mods/31).

======== CUSTOM RESOURCE LIMITS ========

This section is optional if you wish to define custom limits for all resources. By default, this mod
provides a limit of 10. If that's all you want, you don't need to change anything.

Alternatively, the file "custom_limits.txt" defines the max amount for each crafting resource.
You can change the number after the "=" to any integer (whole number) starting at 1. Do not change the order of the items.

After changing the limits, you need to place "ndarc.exe" in the same directory
as this file. You can then run the "patch_inventory.exe" program. This will create a new ".psarc" file 
with your custom limits as its name. Copy this file into your mods folder. Make sure to remove
any previous files associated with this mod, as they will otherwise conflict. 

======== FUTURE UPDATES ========

As with my last mod (https://www.nexusmods.com/thelastofuspart2/mods/210), having to create a new .psarc file
for every limit change isn't great. In the future, changing values like this via the modmanager will hopefully be possible on the fly, and should make mods like this a lot cleaner.


======== CHANGELOG ========

* 1.1.0 | Fixed extra revolver ammo
* 1.0.0 | Release