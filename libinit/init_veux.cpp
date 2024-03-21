/*
 * Copyright (C) 2021-2022 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_dalvik_heap.h>
#include <libinit_variant.h>
#include <libinit_utils.h>

#include "vendor_init.h"

#define FINGERPRINT_GL "POCO/veux_global-user 13 TKQ1.221114.001 V14.0.6.0.TKCMIXM release-keys"
#define FINGERPRINT_CN "Redmi/veux_global/veux:13/TKQ1.221114.001/V14.0.6.0.TKCMIXM:user/release-keys"

static const variant_info_t veux_global_info = {
    .hwc_value = "",
    .sku_value = "veux_p_global",

    .brand = "POCO",
    .device = "veux",
    .model = "POCO X4 pro 5G",
    .mod_device = "veux_p_global",
    .build_fingerprint = FINGERPRINT_GL,
};

static const variant_info_t peux_in_info = {
    .hwc_value = "",
    .sku_value = "peux_p_in",

    .brand = "POCO",
    .device = "peux",
    .model = "POCO X4 pro 5G",
//  .mod_device = "veux_in_global",
    .mod_device = "veux_p_global", // Fixed miuicamera crash
    .build_fingerprint = FINGERPRINT_GL,
};

static const variant_info_t veux_cn_info = {
    .hwc_value = "",
    .sku_value = "veux_cn",

    .brand = "Redmi",
    .device = "veux",
    .model = "Redmi Note 11E pro 5G",
//  .mod_device = "veux",
    .mod_device = "veux_global", // Fixed miuicamera crash
    .build_fingerprint = FINGERPRINT_CN,
};

static const variant_info_t veux_global_info = {
    .hwc_value = "",
    .sku_value = "veux_global",

    .brand = "Redmi",
    .device = "veux",
    .model = "Redmi Note 11 pro 5G",
//  .mod_device = "veux",
    .mod_device = "veux_global", // Fixed miuicamera crash
    .build_fingerprint = FINGERPRINT_CN,
};

static const variant_info_t peux_in_info = {
    .hwc_value = "",
    .sku_value = "peux_in",

    .brand = "Redmi",
    .device = "peux",
    .model = "Redmi Note 11 pro+",
//  .mod_device = "veux",
    .mod_device = "veux_global", // Fixed miuicamera crash
    .build_fingerprint = FINGERPRINT_CN,
};

static const variant_info_t peux_x_info = {
    .hwc_value = "",
    .sku_value = "veux_x",

    .brand = "Redmi",
    .device = "veux",
    .model = "Redmi Note 11 Pro",
//  .mod_device = "veux",
    .mod_device = "veux_global", // Fixed miuicamera crash
    .build_fingerprint = FINGERPRINT_CN,
};

static const std::vector<variant_info_t> variants = {
    veux_global_info,
    peux_in_info,
    veux_global_info,
    veux_cn_info,
    peux_in_info,
    veux_x_info,
};

void vendor_load_properties() {
    set_dalvik_heap();
    search_variant(variants);

    // SafetyNet workaround
    property_override("ro.boot.verifiedbootstate", "green");
}
