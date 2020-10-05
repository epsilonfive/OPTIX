# Exported from https://tiplanet.org/pb/ on Mon Oct  5 22:07:15 2020 (CEST)

# ----------------------------
# Program Options
# ----------------------------

NAME         ?= OPTIX
ICON         ?= icon.png
DESCRIPTION  ?= "OPTIX CE 2.0.0"
COMPRESSED   ?= YES
ARCHIVED     ?= YES

# ----------------------------
# Compile Options
# ----------------------------

# That one gets passed by builder.sh inside EXTRA_CFLAGS
OPT_MODE      =
EXTRA_CFLAGS ?= -Oz -W -Wall -Wwrite-strings -Wno-unknown-pragmas -Wno-incompatible-library-redeclaration -Wno-main-return-type

# ----------------------------
# Debug Options
# ----------------------------

OUTPUT_MAP   ?= NO

include $(CEDEV)/include/.makefile

