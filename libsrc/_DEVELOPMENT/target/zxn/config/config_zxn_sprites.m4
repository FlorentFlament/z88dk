divert(-1)

###############################################################
# HARDWARE SPRITES USER CONFIGURATION
# rebuild the library if changes are made
#

# In total 64 sprites of size 16x16 pixels are supported with
# a limit of 12 visible per scanline.  Sprites of lowest
# priority are simply not drawn if the limit is passed.  Sprite
# priority is determined by sprite number 0-63 where a higher
# number corresponds to a higher priority sprite.

# Each of the 64 sprites are described by a four-byte sprite
# attribute which is written to port 0x57.  The four
# byte sprite attribute determines the sprite's x,y coordinate,
# pattern id (index of 16x16 graphic to use) and various flags
# controlling visibility, rotation and mirroring.  The x,y space
# is 320x256 pixels with the range (32,32) to (287,223) inclusive
# corresponding to the normal 256x192 display area of the zx next.
# Coordinates outside this central area correspond to sprites
# displaying on top of the border area.

# Bits in nextreg 21 enable the sprite layer and determine if
# sprites should be clipped to the active display area (ie, if
# sprites are clipped to (32,32)->(287,223)).  Sprites can also
# be clipped to an arbitrary window in the main display's
# 256x192 area but this bit will override that clipping rectangle
# if set.

# Each sprite's four-byte attribute also identifies which pattern
# is displayed for the sprite.  The pattern is simply an index 0-63
# that identifies an associated 16x16 pixel image.  In total
# 64 such images are written to the fpga's sprite pattern memory
# via port 0x5b.  The 16x16 pixel images are one byte per pixel
# stored in left to right, top to bottom order.  Each byte is 
# a colour index into the sprite palette.  A nibble among each of
# the sprites' four attribute bytes acts as an offset for this
# palette such that the pattern index is increased by this nibble
# amount (*16) to modify the colour.  In this way several sprites
# can share the same image but have different colours applied.
# The lookup in the sprite palette yields another 8-bit index
# that is then passed through the sprite's RGB333 palette to
# determine final 9-bit colour.  If the resulting colour matches
# the global transparency colour, the sprite will be transparent
# in that pixel.

# Larger sprites can be formed by placing individual sprites
# next to each other.  In these cases, care must be taken to
# change positions of the consistent sprites during vbi so that
# relative movements are not seen while the screen is drawn.

# There are three logical layers of video generated by the
# zx next.  One layer is the ula screen, another is layer 2 and
# the third is the sprites layer.  The layers can be stacked
# atop each other in any order, with underlying layers
# visible in transparent portions of overhead layers.

# NEXTREG 20: Global Transparency Colour
#
# define(`__REG_GLOBAL_TRANSPARENCY_COLOR', 20)  # the transparent RGB332 colour

# NEXTREG 21: Layer Priority
#
# define(`__REG_SPRITE_LAYER_SYSTEM', 21)
# define(`__RSLS_ENABLE_LORES', 0x80)
# define(`__RSLS_LAYER_PRIORITY_SLU', 0x00)   # sprites on top, layer 2, ula on bottom
# define(`__RSLS_LAYER_PRIORITY_LSU', 0x04)
# define(`__RSLS_LAYER_PRIORITY_SUL', 0x08)
# define(`__RSLS_LAYER_PRIORITY_LUS', 0x0c)
# define(`__RSLS_LAYER_PRIORITY_USL', 0x10)
# define(`__RSLS_LAYER_PRIORITY_ULS', 0x14)
# define(`__RSLS_SPRITES_OVER_BORDER', 0x02)  # sprites display in border, overrides clipping window
# define(`__RSLS_SPRITES_VISIBLE', 0x01)      # sprite layer is enabled

# NEXTREG 25: Sprite clipping rectangle, coordinates are inclusive
#
# Send clipping rectangle as XL,XR,YT,YB in pixels (reset internal index: register 28)
# The clipping rectangle is in the main 256x192 display area and uses that coordinate space.
# This clipping rectangle is overridden by the border clipping bit in register 21.
#
# define(`__REG_CLIP_WINDOW_SPRITES', 25)

# NEXTREG 28: Clipping Window Control
#
# define(`__REG_CLIP_WINDOW_CONTROL', 28)
# define(`__RCWC_RESET_ULA_CLIP_INDEX', 0x04)
# define(`__RCWC_RESET_SPRITE_CLIP_INDEX', 0x02)  # reset internal index for nextreg 25
# define(`__RCWC_RESET_LAYER_2_CLIP_INDEX', 0x01)

# PORT 0x303B: Sprite Slot Selection (write only)

define(`__IO_SPRITE_SLOT', 0x303b)

# PORT 0x303B: Global Sprites Flag (read only)
# Reading from the port resets the bits

define(`__IO_SPRITE_FLAGS', 0x303b)
define(`__ISF_MAX_SPRITES_PER_LINE', 0x02)  # set if more than 12 sprites appear on any scanline
define(`__ISF_COLLISION', 0x01)             # set if non-transparent pixels of any two sprites overlap

# PORT 0x53: Sprite Palette (write only)
#
# Each sprite's 8-bit pixel value passes through this palette to generate
# a new 8-bit value.  This 8-bit value is then passed through the sprite
# RGB333 palette to produce a 9-bit colour.  The 256 bytes of this palette
# are written to this port after selecting the initial index 0-255 via
# port 0x303b.  Each write auto-increments the palette index.

define(`__IO_SPRITE_PALETTE', 0x53)

# PORT 0x57: Sprite Attributes (write only)
#
# Each of the 64 sprites are described by a four byte attribute:
#   BYTE 0 : X position (bits 7..0)
#   BYTE 1 : Y position (0-255)
#   BYTE 2 : bits 7..4 palette offset, bit 3 = X mirror, bit 2 = Y mirror, bit 1 = rotate, bit 0 = X MSB
#   BYTE 3 : bit 7 = visible, bits 5..0 pattern index (0-63)
# To write a specific sprite's attributes, write the sprite_number to the slot selection port 0x303b
# and then write the bytes to this port.  Each write auto-increments the attribute index.

define(`__IO_SPRITE_ATTRIBUTE', 0x57)

# PORT 0x5B: Sprite Patterns (write only)
#
# Up to 64 sprite patterns can exist, with each pattern 16x16 pixels in size.  Each pixel
# is 8-bits so each each sprite pattern occupies 256 bytes.  To change a sprite pattern,
# first write the pattern id 0-63 to the slot selection port 0x303b and then write the bytes
# to this port.  Each write auto-increments the pattern index.

define(`__IO_SPRITE_PATTERN', 0x5b)

#
# END OF USER CONFIGURATION
###############################################################

divert(0)

dnl#
dnl# COMPILE TIME CONFIG EXPORT FOR ASSEMBLY LANGUAGE
dnl#

ifdef(`CFG_ASM_PUB',
`
PUBLIC `__IO_SPRITE_SLOT'

PUBLIC `__IO_SPRITE_FLAGS'
PUBLIC `__ISF_MAX_SPRITES_PER_LINE'
PUBLIC `__ISF_COLLISION'

PUBLIC `__IO_SPRITE_PALETTE'

PUBLIC `__IO_SPRITE_ATTRIBUTE'

PUBLIC `__IO_SPRITE_PATTERN'
')

dnl#
dnl# LIBRARY BUILD TIME CONFIG FOR ASSEMBLY LANGUAGE
dnl#

ifdef(`CFG_ASM_DEF',
`
defc `__IO_SPRITE_SLOT' = __IO_SPRITE_SLOT

defc `__IO_SPRITE_FLAGS' = __IO_SPRITE_FLAGS
defc `__ISF_MAX_SPRITES_PER_LINE' = __ISF_MAX_SPRITES_PER_LINE
defc `__ISF_COLLISION' = __ISF_COLLISION

defc `__IO_SPRITE_PALETTE' = __IO_SPRITE_PALETTE

defc `__IO_SPRITE_ATTRIBUTE' = __IO_SPRITE_ATTRIBUTE

defc `__IO_SPRITE_PATTERN' = __IO_SPRITE_PATTERN
')

dnl#
dnl# COMPILE TIME CONFIG EXPORT FOR C
dnl#

ifdef(`CFG_C_DEF',
`
`#define' `__IO_SPRITE_SLOT'  __IO_SPRITE_SLOT

`#define' `__IO_SPRITE_FLAGS'  __IO_SPRITE_FLAGS
`#define' `__ISF_MAX_SPRITES_PER_LINE'  __ISF_MAX_SPRITES_PER_LINE
`#define' `__ISF_COLLISION'  __ISF_COLLISION

`#define' `__IO_SPRITE_PALETTE'  __IO_SPRITE_PALETTE

`#define' `__IO_SPRITE_ATTRIBUTE'  __IO_SPRITE_ATTRIBUTE

`#define' `__IO_SPRITE_PATTERN'  __IO_SPRITE_PATTERN
')
