# Walugen - Expanding the possibilities for themes!

## This program extends the capabilities of pywal/hellwal and is written entirely in C.

## Building

```bash
git clone https://github.com/SmaileXM/Walugen.git
cd Walugen
cmake -S . -B build && make -C build
```
## Using 

#### To call for help, use:
```bash
walugen -h
```

#### To specify the backend for applying colors, use the -b flag.
```bash
walugen -b pywal # or hellwal
```

#### To specify the backend for applying wallpapers, use the -w flag.
```bash
walugen -w swww # or swaybg
```

#### Specify the path to the wallpaper.
```bash
walugen -i path/to/wallpaper -b pywal -w swww
```
>> Flags can be written in any order.

#### To skip any action, you can use the "null" keyword when specifying backends.

Examples:
```bash
walugen -i wallpaper -b null -w swww 
```
> In this case, colors will not be applied.

```bash
walugen -i wallpaper -b pywal -w null
```
> In this case, the wallpaper will not be used.

## features in the future

**.ini config** - To create your own backends and settings.

**random wallpaper** - Support for random wallpapers from a specified directory with file extension checking.

**Improved feature skipping** - Improved the system for skipping functions without explicitly specifying "no".