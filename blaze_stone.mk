#
# Copyright (C) 2022 The bananaOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit some common banana stuff.
$(call inherit-product, vendor/blaze/config/common.mk)

# Inherit from stone device
$(call inherit-product, device/xiaomi/stone/device.mk)

# Device props
TARGET_SUPPORTS_QUICK_TAP := true
TARGET_FACE_UNLOCK_SUPPORTED := true
TARGET_DISABLE_EPPE := true
TARGET_SUPPORTS_64_BIT_APPS := true
TARGET_DEBLOAT := true
LINAG_MAINTAINER := Kami_Nomi
LINEAGE_MAINTAINER := Kami_Nomi

#Blaze Flags
WITH_GAPPS := true
BLAZE_MAINTAINER := Nomi noob

# Charging Animation
TARGET_USE_PIXEL_CHARGER := true

# Use Prebuilt Kernel
#PREBUILT_KERNEL := true

# Device identifier. This must come after all inclusions.
PRODUCT_NAME := blaze_stone
PRODUCT_DEVICE := stone
PRODUCT_MANUFACTURER := Xiaomi
PRODUCT_BRAND := Xiaomi

PRODUCT_GMS_CLIENTID_BASE := android-xiaomi
