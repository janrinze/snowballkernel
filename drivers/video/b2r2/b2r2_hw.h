/*
 * Copyright (C) ST-Ericsson SA 2010
 *
 * ST-Ericsson B2R2 hw definitions
 *
 * Author: Fredrik Allansson <fredrik.allansson@stericsson.com>
 * for ST-Ericsson.
 *
 * License terms: GNU General Public License (GPL), version 2.
 */

#ifndef B2R2_HW_H__
#define B2R2_HW_H__

#include <linux/bitops.h>

/* Scaling works in strips 128 pixels wide */
#define B2R2_RESCALE_MAX_WIDTH 128

/* Rotation works in strips 16 pixels wide */
#define B2R2_ROTATE_MAX_WIDTH 16

/* B2R2 color formats */
#define B2R2_COLOR_FORMAT_SHIFT 16
enum b2r2_native_fmt {
	/* RGB formats */
	B2R2_NATIVE_RGB565 = 0x00 << B2R2_COLOR_FORMAT_SHIFT,
	B2R2_NATIVE_RGB888 = 0x01 << B2R2_COLOR_FORMAT_SHIFT,
	B2R2_NATIVE_ARGB8565 = 0x04 << B2R2_COLOR_FORMAT_SHIFT,
	B2R2_NATIVE_ARGB8888 = 0x05 << B2R2_COLOR_FORMAT_SHIFT,
	B2R2_NATIVE_ARGB1555 = 0x06 << B2R2_COLOR_FORMAT_SHIFT,
	B2R2_NATIVE_ARGB4444 = 0x07 << B2R2_COLOR_FORMAT_SHIFT,

	/* YCbCr formats */
	B2R2_NATIVE_YCBCR888 = 0x10 << B2R2_COLOR_FORMAT_SHIFT,
	B2R2_NATIVE_YCBCR422R = 0x12 << B2R2_COLOR_FORMAT_SHIFT,
	B2R2_NATIVE_AYCBCR8888 = 0x15 << B2R2_COLOR_FORMAT_SHIFT,
	B2R2_NATIVE_YCBCR42X_MB = 0x14 << B2R2_COLOR_FORMAT_SHIFT,
	B2R2_NATIVE_YCBCR42X_R2B = 0x16 << B2R2_COLOR_FORMAT_SHIFT,
	B2R2_NATIVE_YCBCR42X_MBN = 0x0e << B2R2_COLOR_FORMAT_SHIFT,

	/* CLUT formats */
	B2R2_NATIVE_CLUT2 = 0x09 << B2R2_COLOR_FORMAT_SHIFT,
	B2R2_NATIVE_CLUT8 = 0x0b << B2R2_COLOR_FORMAT_SHIFT,
	B2R2_NATIVE_ACLUT44 = 0x0c << B2R2_COLOR_FORMAT_SHIFT,
	B2R2_NATIVE_ACLUT88 = 0x0d << B2R2_COLOR_FORMAT_SHIFT,

	/* Misc. formats */
	B2R2_NATIVE_A1 = 0x18 << B2R2_COLOR_FORMAT_SHIFT,
	B2R2_NATIVE_A8 = 0x19 << B2R2_COLOR_FORMAT_SHIFT,
	B2R2_NATIVE_YUV	= 0x1e << B2R2_COLOR_FORMAT_SHIFT,
	B2R2_NATIVE_BYTE = 0x1f << B2R2_COLOR_FORMAT_SHIFT,
};

/* B2R2_CIC register values */
enum b2r2_cic {
	B2R2_CIC_COLOR_FILL =     BIT(1),/*0x00000002*/
	B2R2_CIC_SOURCE_1 =       BIT(2),/*0x00000004*/
	B2R2_CIC_SOURCE_2 =       BIT(3),/*0x00000008*/
	B2R2_CIC_SOURCE_3 =       BIT(4),/*0x00000010*/
	B2R2_CIC_CLIP_WINDOW =    BIT(5),/*0x00000020*/
	B2R2_CIC_CLUT =           BIT(6),/*0x00000040*/
	B2R2_CIC_FILTER_CONTROL = BIT(7),/*0x00000080*/
	B2R2_CIC_RESIZE_CHROMA =  BIT(8),/*0x00000100*/
	B2R2_CIC_RESIZE_LUMA =    BIT(9),/*0x00000200*/
	B2R2_CIC_FLICKER_COEFF =  BIT(10),/*0x00000400*/
	B2R2_CIC_COLOR_KEY =      BIT(11),/*0x00000800*/
	B2R2_CIC_XYL =            BIT(12),/*0x00001000*/
	B2R2_CIC_SAU =            BIT(13),/*0x00002000*/
	B2R2_CIC_IVMX =           BIT(14),/*0x00004000*/
	B2R2_CIC_OVMX =           BIT(15),/*0x00008000*/
	B2R2_CIC_PACEDOT =        BIT(16),/*0x00010000*/
	B2R2_CIC_VC1 =            BIT(17)/*0x00020000*/
};

/* B2R2_INS register values */
#define B2R2_INS_SOURCE_1_SHIFT 0
#define B2R2_INS_SOURCE_2_SHIFT 3
#define B2R2_INS_SOURCE_3_SHIFT 5
#define B2R2_INS_IVMX_SHIFT 6
#define B2R2_INS_CLUTOP_SHIFT 7
#define B2R2_INS_RESCALE2D_SHIFT 8
#define B2R2_INS_FLICK_FILT_SHIFT 9
#define B2R2_INS_RECT_CLIP_SHIFT 10
#define B2R2_INS_CKEY_SHIFT 11
#define B2R2_INS_OVMX_SHIFT 12
#define B2R2_INS_DEI_SHIFT 13
#define B2R2_INS_PLANE_MASK_SHIFT 14
#define B2R2_INS_XYL_SHIFT 15
#define B2R2_INS_DOT_SHIFT 16
#define B2R2_INS_VC1R_SHIFT 17
#define B2R2_INS_ROTATION_SHIFT 18
#define B2R2_INS_PACE_DOWN_SHIFT 30
#define B2R2_INS_BLITCOMPIRQ_SHIFT 31
enum b2r2_ins {
	/* Source 1 config */
	B2R2_INS_SOURCE_1_FETCH_FROM_MEM =      0x1 << B2R2_INS_SOURCE_1_SHIFT,
	B2R2_INS_SOURCE_1_COLOR_FILL_REGISTER = 0x3 << B2R2_INS_SOURCE_1_SHIFT,
	B2R2_INS_SOURCE_1_DIRECT_COPY =         0x4 << B2R2_INS_SOURCE_1_SHIFT,
	B2R2_INS_SOURCE_1_DIRECT_FILL =         0x7 << B2R2_INS_SOURCE_1_SHIFT,

	/* Source 2 config */
	B2R2_INS_SOURCE_2_FETCH_FROM_MEM =      0x1 << B2R2_INS_SOURCE_2_SHIFT,
	B2R2_INS_SOURCE_2_COLOR_FILL_REGISTER = 0x3 << B2R2_INS_SOURCE_2_SHIFT,

	/* Source 3 config */
	B2R2_INS_SOURCE_3_FETCH_FROM_MEM =      0x1 << B2R2_INS_SOURCE_3_SHIFT,

	/* Other configs */
	B2R2_INS_IVMX_ENABLED =               0x1 << B2R2_INS_IVMX_SHIFT,
	B2R2_INS_CLUTOP_ENABLED =             0x1 << B2R2_INS_CLUTOP_SHIFT,
	B2R2_INS_RESCALE2D_ENABLED =          0x1 << B2R2_INS_RESCALE2D_SHIFT,
	B2R2_INS_FLICK_FILT_ENABLED =         0x1 << B2R2_INS_FLICK_FILT_SHIFT,
	B2R2_INS_RECT_CLIP_ENABLED =          0x1 << B2R2_INS_RECT_CLIP_SHIFT,
	B2R2_INS_CKEY_ENABLED =               0x1 << B2R2_INS_CKEY_SHIFT,
	B2R2_INS_OVMX_ENABLED =               0x1 << B2R2_INS_OVMX_SHIFT,
	B2R2_INS_DEI_ENABLED =                0x1 << B2R2_INS_DEI_SHIFT,
	B2R2_INS_PLANE_MASK_ENABLED =         0x1 << B2R2_INS_PLANE_MASK_SHIFT,
	B2R2_INS_XYL_ENABLED =                0x1 << B2R2_INS_XYL_SHIFT,
	B2R2_INS_DOT_ENABLED =                0x1 << B2R2_INS_DOT_SHIFT,
	B2R2_INS_VC1R_ENABLED =               0x1 << B2R2_INS_VC1R_SHIFT,
	B2R2_INS_ROTATION_ENABLED =           0x1 << B2R2_INS_ROTATION_SHIFT,
	B2R2_INS_PACE_DOWN_ENABLED =          0x1 << B2R2_INS_PACE_DOWN_SHIFT,
	B2R2_INS_BLITCOMPIRQ_ENABLED =        0x1 << B2R2_INS_BLITCOMPIRQ_SHIFT,

};

/* B2R2_ACK register values */
#define B2R2_ACK_MODE_SHIFT 0
#define B2R2_ACK_SWAP_FG_BG_SHIFT 4
#define B2R2_ACK_GALPHA_ROPID_SHIFT 8
#define B2R2_ACK_CKEY_BLUE_SHIFT 16
#define B2R2_ACK_CKEY_GREEN_SHIFT 18
#define B2R2_ACK_CKEY_RED_SHIFT 20
#define B2R2_ACK_CKEY_SEL_SHIFT 22
enum b2r2_ack {
	/* ALU operation modes */
	B2R2_ACK_MODE_LOGICAL_OPERATION =            0x1 << B2R2_ACK_MODE_SHIFT,
	B2R2_ACK_MODE_BLEND_NOT_PREMULT =            0x2 << B2R2_ACK_MODE_SHIFT,
	B2R2_ACK_MODE_BLEND_PREMULT =                0x3 << B2R2_ACK_MODE_SHIFT,
	B2R2_ACK_MODE_CLIPMASK_LOGICAL_FIRST_PASS =  0x4 << B2R2_ACK_MODE_SHIFT,
	B2R2_ACK_MODE_CLIPMASK_BLEND =               0x5 << B2R2_ACK_MODE_SHIFT,
	B2R2_ACK_MODE_BYPASS_S2_S3 =                 0x7 << B2R2_ACK_MODE_SHIFT,
	B2R2_ACK_MODE_CLIPMASK_LOGICAL_SECOND_PASS = 0x8 << B2R2_ACK_MODE_SHIFT,
	B2R2_ACK_MODE_CLIPMASK_XYL_LOGICAL =         0x9 << B2R2_ACK_MODE_SHIFT,
	B2R2_ACK_MODE_CLIPMASK_XYL_BLEND_NOT_PREMULT =
						     0xa << B2R2_ACK_MODE_SHIFT,
	B2R2_ACK_MODE_CLIPMASK_XYL_BLEND_PREMULT =   0xb << B2R2_ACK_MODE_SHIFT,

	/* ALU channel selection */
	B2R2_ACK_SWAP_FG_BG =                  0x1 << B2R2_ACK_SWAP_FG_BG_SHIFT,

	/* Global alpha and ROP IDs */
	B2R2_ACK_ROP_CLEAR =                 0x0 << B2R2_ACK_GALPHA_ROPID_SHIFT,
	B2R2_ACK_ROP_AND =                   0x1 << B2R2_ACK_GALPHA_ROPID_SHIFT,
	B2R2_ACK_ROP_AND_REV =               0x2 << B2R2_ACK_GALPHA_ROPID_SHIFT,
	B2R2_ACK_ROP_COPY =                  0x3 << B2R2_ACK_GALPHA_ROPID_SHIFT,
	B2R2_ACK_ROP_AND_INV =               0x4 << B2R2_ACK_GALPHA_ROPID_SHIFT,
	B2R2_ACK_ROP_NOOP =                  0x5 << B2R2_ACK_GALPHA_ROPID_SHIFT,
	B2R2_ACK_ROP_XOR =                   0x6 << B2R2_ACK_GALPHA_ROPID_SHIFT,
	B2R2_ACK_ROP_OR =                    0x7 << B2R2_ACK_GALPHA_ROPID_SHIFT,
	B2R2_ACK_ROP_NOR =                   0x8 << B2R2_ACK_GALPHA_ROPID_SHIFT,
	B2R2_ACK_ROP_EQUIV =                 0x9 << B2R2_ACK_GALPHA_ROPID_SHIFT,
	B2R2_ACK_ROP_INVERT =                0xa << B2R2_ACK_GALPHA_ROPID_SHIFT,
	B2R2_ACK_ROP_OR_REV =                0xb << B2R2_ACK_GALPHA_ROPID_SHIFT,
	B2R2_ACK_ROP_COPY_INV =              0xc << B2R2_ACK_GALPHA_ROPID_SHIFT,
	B2R2_ACK_ROP_OR_INV =                0xd << B2R2_ACK_GALPHA_ROPID_SHIFT,
	B2R2_ACK_ROP_NAND =                  0xe << B2R2_ACK_GALPHA_ROPID_SHIFT,
	B2R2_ACK_ROP_SET =                   0xf << B2R2_ACK_GALPHA_ROPID_SHIFT,

	/* Color key configuration bits */
	B2R2_ACK_CKEY_BLUE_MATCH_IF_BETWEEN =  0x1 << B2R2_ACK_CKEY_BLUE_SHIFT,
	B2R2_ACK_CKEY_BLUE_MATCH_IF_LT_OR_GT = 0x2 << B2R2_ACK_CKEY_BLUE_SHIFT,
	B2R2_ACK_CKEY_RED_MATCH_IF_BETWEEN =   0x1 << B2R2_ACK_CKEY_GREEN_SHIFT,
	B2R2_ACK_CKEY_RED_MATCH_IF_LT_OR_GT =  0x2 << B2R2_ACK_CKEY_GREEN_SHIFT,
	B2R2_ACK_CKEY_GREEN_MATCH_IF_BETWEEN = 0x1 << B2R2_ACK_CKEY_RED_SHIFT,
	B2R2_ACK_CKEY_GREEN_MATCH_IF_LT_OR_GT = 0x2 << B2R2_ACK_CKEY_RED_SHIFT,

	/* Color key input selection */
	B2R2_ACK_CKEY_SEL_DEST =               0x0 << B2R2_ACK_CKEY_SEL_SHIFT,
	B2R2_ACK_CKEY_SEL_SRC_BEFORE_CLUT =    0x1 << B2R2_ACK_CKEY_SEL_SHIFT,
	B2R2_ACK_CKEY_SEL_SRC_AFTER_CLUT =     0x2 << B2R2_ACK_CKEY_SEL_SHIFT,
	B2R2_ACK_CKEY_SEL_BLANKING_S2_ALPHA =  0x3 << B2R2_ACK_CKEY_SEL_SHIFT,
};

/* Common <S/T>TY defines */
#define B2R2_TY_BITMAP_PITCH_SHIFT 0
#define B2R2_TY_COLOR_FORM_SHIFT 16
#define B2R2_TY_ALPHA_RANGE_SHIFT 21
#define B2R2_TY_MB_ACCESS_MODE_SHIFT 23
#define B2R2_TY_HSO_SHIFT 24
#define B2R2_TY_VSO_SHIFT 25
#define B2R2_TY_SUBBYTE_SHIFT 28
#define B2R2_TY_ENDIAN_SHIFT 30
#define B2R2_TY_SECURE_SHIFT 31

/* Dummy enum for generalization of <S/T>TY registers */
enum b2r2_ty {
	/* Alpha range */
	B2R2_TY_ALPHA_RANGE_128 = 0x0 << B2R2_TY_ALPHA_RANGE_SHIFT,
	B2R2_TY_ALPHA_RANGE_255 = 0x1 << B2R2_TY_ALPHA_RANGE_SHIFT,

	/* Access mode in macro-block organized frame buffers */
	B2R2_TY_MB_ACCESS_MODE_FRAME = 0x0 << B2R2_TY_MB_ACCESS_MODE_SHIFT,
	B2R2_TY_MB_ACCESS_MODE_FIELD = 0x1 << B2R2_TY_MB_ACCESS_MODE_SHIFT,

	/* Horizontal scan order */
	B2R2_TY_HSO_LEFT_TO_RIGHT = 0x0 << B2R2_TY_HSO_SHIFT,
	B2R2_TY_HSO_RIGHT_TO_LEFT = 0x1 << B2R2_TY_HSO_SHIFT,

	/* Vertical scan order */
	B2R2_TY_VSO_TOP_TO_BOTTOM = 0x0 << B2R2_TY_VSO_SHIFT,
	B2R2_TY_VSO_BOTTOM_TO_TOP = 0x1 << B2R2_TY_VSO_SHIFT,

	/* Pixel ordering for sub-byte formats (position of right-most pixel) */
	B2R2_TY_SUBBYTE_MSB = 0x0 << B2R2_TY_SUBBYTE_SHIFT,
	B2R2_TY_SUBBYTE_LSB = 0x1 << B2R2_TY_SUBBYTE_SHIFT,

	/* Bitmap endianess */
	B2R2_TY_ENDIAN_BIG_NOT_LITTLE = 0x1 << B2R2_TY_ENDIAN_SHIFT,

	/* Secureness of the target memory region */
	B2R2_TY_SECURE_UNSECURE = 0x0 << B2R2_TY_SECURE_SHIFT,
	B2R2_TY_SECURE_SECURE =   0x1 << B2R2_TY_SECURE_SHIFT,

	/* Dummy to make sure the data type is large enough */
	B2R2_TY_DUMMY = 0xffffffff,
};

/* B2R2_TTY register values */
#define B2R2_TTY_CB_NOT_CR_SHIFT 22
#define B2R2_TTY_RGB_ROUND_SHIFT 26
#define B2R2_TTY_CHROMA_NOT_LUMA_SHIFT 27
enum b2r2_tty {

	/* Chroma component selection */
	B2R2_TTY_CB_NOT_CR = 0x1 << B2R2_TTY_CB_NOT_CR_SHIFT,

	/* RGB rounding mode */
	B2R2_TTY_RGB_ROUND_NORMAL = 0x0 << B2R2_TTY_RGB_ROUND_SHIFT,
	B2R2_TTY_RGB_ROUND_DITHER = 0x1 << B2R2_TTY_RGB_ROUND_SHIFT,

	/* Component selection for splitted frame buffer formats */
	B2R2_TTY_CHROMA_NOT_LUMA = 0x1 << B2R2_TTY_CHROMA_NOT_LUMA_SHIFT,
};

/* B2R2_S1TY register values */
#define B2R2_S1TY_A1_SUBST_SHIFT 22
#define B2R2_S1TY_ROTATION_SHIFT 27
#define B2R2_S1TY_RGB_EXPANSION_SHIFT 29
enum b2r2_s1ty {

	/* Alpha bit substitution mode for ARGB1555 */
	B2R2_S1TY_A1_SUBST_KEY_MODE = 0x1 << B2R2_S1TY_A1_SUBST_SHIFT,

	/* Input rectangle rotation (NOT YET IMPLEMENTED) */
	B2R2_S1TY_ENABLE_ROTATION = 0x1 << B2R2_S1TY_ROTATION_SHIFT,

	/* RGB expansion mode */
	B2R2_S1TY_RGB_EXPANSION_MSB_DUP = 0x0  << B2R2_S1TY_RGB_EXPANSION_SHIFT,
	B2R2_S1TY_RGB_EXPANSION_LSP_ZERO = 0x1 << B2R2_S1TY_RGB_EXPANSION_SHIFT,
};

/* B2R2_S1TY register values */
#define B2R2_S2TY_A1_SUBST_SHIFT 22
#define B2R2_S2TY_CHROMA_LEFT_SHIFT 26
#define B2R2_S2TY_RGB_EXPANSION_SHIFT 29
enum b2r2_s2ty {

	/* Alpha bit substitution mode for ARGB1555 */
	B2R2_S2TY_A1_SUBST_KEY_MODE = 0x1 << B2R2_S2TY_A1_SUBST_SHIFT,

	/* Chroma left extension */
	B2R2_S2TY_CHROMA_LEFT_EXT_FOLLOWING_PIXEL = 0x0
						<< B2R2_S2TY_CHROMA_LEFT_SHIFT,
	B2R2_S2TY_CHROMA_LEFT_EXT_AVERAGE = 0x1 << B2R2_S2TY_CHROMA_LEFT_SHIFT,

	/* RGB expansion mode */
	B2R2_S2TY_RGB_EXPANSION_MSB_DUP = 0x0  << B2R2_S2TY_RGB_EXPANSION_SHIFT,
	B2R2_S2TY_RGB_EXPANSION_LSP_ZERO = 0x1 << B2R2_S2TY_RGB_EXPANSION_SHIFT,
};

/* B2R2_S1TY register values */
#define B2R2_S3TY_BLANK_ACC_SHIFT 26
enum b2r2_s3ty {
	/* Enables "blank" access on this source (nothing will be fetched from
	   memory) */
	B2R2_S3TY_ENABLE_BLANK_ACCESS = 0x1 << B2R2_S3TY_BLANK_ACC_SHIFT,
};

/* B2R2_<S or T>XY register values */
#define B2R2_XY_X_SHIFT 0
#define B2R2_XY_Y_SHIFT 16

/* B2R2_<S or T>SZ register values */
#define B2R2_SZ_WIDTH_SHIFT 0
#define B2R2_SZ_HEIGHT_SHIFT 16

/* Clip window offset (top left coordinates) */
#define B2R2_CWO_X_SHIFT 0
#define B2R2_CWO_Y_SHIFT 16

/* Clip window stop (bottom right coordinates) */
#define B2R2_CWS_X_SHIFT 0
#define B2R2_CWS_Y_SHIFT 16

/* Color look-up table */
enum b2r2_cco {
	B2R2_CCO_CLUT_COLOR_CORRECTION = (1 << 16),
	B2R2_CCO_CLUT_UPDATE = (1 << 18),
	B2R2_CCO_CLUT_ON_S1 = (1 << 15)
};

/* Filter control (2D resize control) */
enum b2r2_fctl {
	/* Horizontal 2D filter mode */
	B2R2_FCTL_HF2D_MODE_ENABLE_COLOR_CHANNEL_FILTER = BIT(0),
	B2R2_FCTL_HF2D_MODE_ENABLE_ALPHA_CHANNEL_FILTER = BIT(1),
	B2R2_FCTL_HF2D_MODE_ENABLE_RESIZER = BIT(2),

	/* Vertical 2D filter mode */
	B2R2_FCTL_VF2D_MODE_ENABLE_COLOR_CHANNEL_FILTER = BIT(4),
	B2R2_FCTL_VF2D_MODE_ENABLE_ALPHA_CHANNEL_FILTER = BIT(5),
	B2R2_FCTL_VF2D_MODE_ENABLE_RESIZER = BIT(6),

	/* Alpha borders */
	B2R2_FCTL_ENABLE_ALPHA_BORDER_RIGHT = BIT(12),
	B2R2_FCTL_ENABLE_ALPHA_BORDER_LEFT = BIT(13),
	B2R2_FCTL_ENABLE_ALPHA_BORDER_BOTTOM = BIT(14),
	B2R2_FCTL_ENABLE_ALPHA_BORDER_TOP = BIT(15),

	/* Luma path horizontal 2D filter mode */
	B2R2_FCTL_LUMA_HF2D_MODE_ENABLE_FILTER = BIT(24),
	B2R2_FCTL_LUMA_HF2D_MODE_ENABLE_RESIZER = BIT(25),

	/* Luma path vertical 2D filter mode */
	B2R2_FCTL_LUMA_VF2D_MODE_ENABLE_FILTER = BIT(28),
	B2R2_FCTL_LUMA_VF2D_MODE_ENABLE_RESIZER = BIT(29),
};

/* Resize scaling factor */
#define B2R2_RSF_HSRC_INC_SHIFT 0
#define B2R2_RSF_VSRC_INC_SHIFT 16

/* Resizer initialization */
#define B2R2_RZI_HSRC_INIT_SHIFT 0
#define B2R2_RZI_HNB_REPEAT_SHIFT 12
#define B2R2_RZI_VSRC_INIT_SHIFT 16
#define B2R2_RZI_VNB_REPEAT_SHIFT 28

/* Default values for the resizer */
#define B2R2_RZI_DEFAULT_HNB_REPEAT (3 << B2R2_RZI_HNB_REPEAT_SHIFT)
#define B2R2_RZI_DEFAULT_VNB_REPEAT (3 << B2R2_RZI_VNB_REPEAT_SHIFT)


/* Bus plug configuration registers */
enum b2r2_plug_opcode_size {
	B2R2_PLUG_OPCODE_SIZE_8 =  0x3,
	B2R2_PLUG_OPCODE_SIZE_16 = 0x4,
	B2R2_PLUG_OPCODE_SIZE_32 = 0x5,
	B2R2_PLUG_OPCODE_SIZE_64 = 0x6,
};

enum b2r2_plug_chunk_size {
	B2R2_PLUG_CHUNK_SIZE_1 =   0x0,
	B2R2_PLUG_CHUNK_SIZE_2 =   0x1,
	B2R2_PLUG_CHUNK_SIZE_4 =   0x2,
	B2R2_PLUG_CHUNK_SIZE_8 =   0x3,
	B2R2_PLUG_CHUNK_SIZE_16 =  0x4,
	B2R2_PLUG_CHUNK_SIZE_32 =  0x5,
	B2R2_PLUG_CHUNK_SIZE_64 =  0x6,
	B2R2_PLUG_CHUNK_SIZE_128 = 0x7,
};

enum b2r2_plug_message_size {
	B2R2_PLUG_MESSAGE_SIZE_1 =   0x0,
	B2R2_PLUG_MESSAGE_SIZE_2 =   0x1,
	B2R2_PLUG_MESSAGE_SIZE_4 =   0x2,
	B2R2_PLUG_MESSAGE_SIZE_8 =   0x3,
	B2R2_PLUG_MESSAGE_SIZE_16 =  0x4,
	B2R2_PLUG_MESSAGE_SIZE_32 =  0x5,
	B2R2_PLUG_MESSAGE_SIZE_64 =  0x6,
	B2R2_PLUG_MESSAGE_SIZE_128 = 0x7,
};

enum b2r2_plug_page_size {
	B2R2_PLUG_PAGE_SIZE_64 =  0x0,
	B2R2_PLUG_PAGE_SIZE_128 = 0x1,
	B2R2_PLUG_PAGE_SIZE_256 = 0x2,
};

/* Default opcode size */
#if defined(CONFIG_B2R2_OPSIZE_8)
#  define B2R2_PLUG_OPCODE_SIZE_DEFAULT B2R2_PLUG_OPCODE_SIZE_8
#elif defined(CONFIG_B2R2_OPSIZE_16)
#  define B2R2_PLUG_OPCODE_SIZE_DEFAULT B2R2_PLUG_OPCODE_SIZE_16
#elif defined(CONFIG_B2R2_OPSIZE_32)
#  define B2R2_PLUG_OPCODE_SIZE_DEFAULT B2R2_PLUG_OPCODE_SIZE_32
#elif defined(CONFIG_B2R2_OPSIZE_64)
#  define B2R2_PLUG_OPCODE_SIZE_DEFAULT B2R2_PLUG_OPCODE_SIZE_64
#else
#  define B2R2_PLUG_OPCODE_SIZE_DEFAULT 0
#endif

/* Default chunk size */
#if defined(CONFIG_B2R2_CHSIZE_1)
#  define B2R2_PLUG_CHUNK_SIZE_DEFAULT B2R2_PLUG_CHUNK_SIZE_1
#elif defined(CONFIG_B2R2_CHSIZE_2)
#  define B2R2_PLUG_CHUNK_SIZE_DEFAULT B2R2_PLUG_CHUNK_SIZE_2
#elif defined(CONFIG_B2R2_CHSIZE_4)
#  define B2R2_PLUG_CHUNK_SIZE_DEFAULT B2R2_PLUG_CHUNK_SIZE_4
#elif defined(CONFIG_B2R2_CHSIZE_8)
#  define B2R2_PLUG_CHUNK_SIZE_DEFAULT B2R2_PLUG_CHUNK_SIZE_8
#elif defined(CONFIG_B2R2_CHSIZE_16)
#  define B2R2_PLUG_CHUNK_SIZE_DEFAULT B2R2_PLUG_CHUNK_SIZE_16
#elif defined(CONFIG_B2R2_CHSIZE_32)
#  define B2R2_PLUG_CHUNK_SIZE_DEFAULT B2R2_PLUG_CHUNK_SIZE_32
#elif defined(CONFIG_B2R2_CHSIZE_64)
#  define B2R2_PLUG_CHUNK_SIZE_DEFAULT B2R2_PLUG_CHUNK_SIZE_64
#elif defined(CONFIG_B2R2_CHSIZE_128)
#  define B2R2_PLUG_CHUNK_SIZE_DEFAULT B2R2_PLUG_CHUNK_SIZE_128
#else
#  define B2R2_PLUG_CHUNK_SIZE_DEFAULT 0
#endif

/* Default message size */
#if defined(CONFIG_B2R2_MGSIZE_1)
#  define B2R2_PLUG_MESSAGE_SIZE_DEFAULT B2R2_PLUG_MESSAGE_SIZE_1
#elif defined(CONFIG_B2R2_MGSIZE_2)
#  define B2R2_PLUG_MESSAGE_SIZE_DEFAULT B2R2_PLUG_MESSAGE_SIZE_2
#elif defined(CONFIG_B2R2_MGSIZE_4)
#  define B2R2_PLUG_MESSAGE_SIZE_DEFAULT B2R2_PLUG_MESSAGE_SIZE_4
#elif defined(CONFIG_B2R2_MGSIZE_8)
#  define B2R2_PLUG_MESSAGE_SIZE_DEFAULT B2R2_PLUG_MESSAGE_SIZE_8
#elif defined(CONFIG_B2R2_MGSIZE_16)
#  define B2R2_PLUG_MESSAGE_SIZE_DEFAULT B2R2_PLUG_MESSAGE_SIZE_16
#elif defined(CONFIG_B2R2_MGSIZE_32)
#  define B2R2_PLUG_MESSAGE_SIZE_DEFAULT B2R2_PLUG_MESSAGE_SIZE_32
#elif defined(CONFIG_B2R2_MGSIZE_64)
#  define B2R2_PLUG_MESSAGE_SIZE_DEFAULT B2R2_PLUG_MESSAGE_SIZE_64
#elif defined(CONFIG_B2R2_MGSIZE_128)
#  define B2R2_PLUG_MESSAGE_SIZE_DEFAULT B2R2_PLUG_MESSAGE_SIZE_128
#else
#  define B2R2_PLUG_MESSAGE_SIZE_DEFAULT 0
#endif

/* Default page size */
#if defined(CONFIG_B2R2_PGSIZE_64)
#  define B2R2_PLUG_PAGE_SIZE_DEFAULT B2R2_PLUG_PAGE_SIZE_64
#elif defined(CONFIG_B2R2_PGSIZE_128)
#  define B2R2_PLUG_PAGE_SIZE_DEFAULT B2R2_PLUG_PAGE_SIZE_128
#elif defined(CONFIG_B2R2_PGSIZE_256)
#  define B2R2_PLUG_PAGE_SIZE_DEFAULT B2R2_PLUG_PAGE_SIZE_256
#else
#  define B2R2_PLUG_PAGE_SIZE_DEFAULT 0
#endif

/*  VMX register values for RGB to YUV color conversion */
/*  Magic numbers from 27.11 in DB8500_DesignSpecification_v2.5.pdf */

/* 601 Video Matrix (standard 601 conversion) */
#define B2R2_VMX0_RGB_TO_YUV_601_VIDEO 0x107e4beb
#define B2R2_VMX1_RGB_TO_YUV_601_VIDEO 0x0982581d
#define B2R2_VMX2_RGB_TO_YUV_601_VIDEO 0xfa9ea483
#define B2R2_VMX3_RGB_TO_YUV_601_VIDEO 0x08000080

/* 601 Gfx Matrix (full range conversion) */
#define B2R2_VMX0_RGB_TO_YUV_601_GFX 0x0e1e8bee
#define B2R2_VMX1_RGB_TO_YUV_601_GFX 0x08420419
#define B2R2_VMX2_RGB_TO_YUV_601_GFX 0xfb5ed471
#define B2R2_VMX3_RGB_TO_YUV_601_GFX 0x08004080

/* 709 Video Matrix (standard 709 conversion) */
#define B2R2_VMX0_RGB_TO_YUV_709_VIDEO 0x107e27f4
#define B2R2_VMX1_RGB_TO_YUV_709_VIDEO 0x06e2dc13
#define B2R2_VMX2_RGB_TO_YUV_709_VIDEO 0xfc5e6c83
#define B2R2_VMX3_RGB_TO_YUV_709_VIDEO 0x08000080

/* 709 Gfx Matrix (standard 709 conversion) */
#define B2R2_VMX0_RGB_TO_YUV_709_GFX 0x0e3e6bf5
#define B2R2_VMX1_RGB_TO_YUV_709_GFX 0x05e27410
#define B2R2_VMX2_RGB_TO_YUV_709_GFX 0xfcdea471
#define B2R2_VMX3_RGB_TO_YUV_709_GFX 0x08004080

/* VMX register values for YUV to RGB color conversion */

/* 601 Video Matrix (standard 601 conversion) */
#define B2R2_VMX0_YUV_TO_RGB_601_VIDEO 0x2c440000
#define B2R2_VMX1_YUV_TO_RGB_601_VIDEO 0xe9a403aa
#define B2R2_VMX2_YUV_TO_RGB_601_VIDEO 0x0004013f
#define B2R2_VMX3_YUV_TO_RGB_601_VIDEO 0x34f21322

/* 601 Gfx Matrix (full range conversion) */
#define B2R2_VMX0_YUV_TO_RGB_601_GFX 0x3324a800
#define B2R2_VMX1_YUV_TO_RGB_601_GFX 0xe604ab9c
#define B2R2_VMX2_YUV_TO_RGB_601_GFX 0x0004a957
#define B2R2_VMX3_YUV_TO_RGB_601_GFX 0x32121eeb

/* 709 Video Matrix (standard 709 conversion) */
#define B2R2_VMX0_YUV_TO_RGB_709_VIDEO 0x31440000
#define B2R2_VMX1_YUV_TO_RGB_709_VIDEO 0xf16403d1
#define B2R2_VMX2_YUV_TO_RGB_709_VIDEO 0x00040145
#define B2R2_VMX3_YUV_TO_RGB_709_VIDEO 0x33b14b18

/* 709 Gfx Matrix (standard 709 conversion) */
#define B2R2_VMX0_YUV_TO_RGB_709_GFX 0x3964a800
#define B2R2_VMX1_YUV_TO_RGB_709_GFX 0xef04abc9
#define B2R2_VMX2_YUV_TO_RGB_709_GFX 0x0004a95f
#define B2R2_VMX3_YUV_TO_RGB_709_GFX 0x307132df

/* VMX register values for RGB to BGR conversion */
#define B2R2_VMX0_RGB_TO_BGR 0x00000100
#define B2R2_VMX1_RGB_TO_BGR 0x00040000
#define B2R2_VMX2_RGB_TO_BGR 0x20000000
#define B2R2_VMX3_RGB_TO_BGR 0x00000000

/* VMX register values for BGR to YUV color conversion */
/* Note: All BGR -> YUV values are calculated by multiplying
 * the RGB -> YUV matrices [A], with [S] to form [A]x[S] where
 *     |0 0 1|
 * S = |0 1 0|
 *     |1 0 0|
 * Essentially swapping first and third columns in
 * the matrices (VMX0, VMX1 and VMX2 values).
 * The offset vector VMX3 remains untouched.
 * Put another way, the value of bits 0 through 9
 * is swapped with the value of
 * bits 20 through 31 in VMX0, VMX1 and VMX2,
 * taking into consideration the compression
 * that is used on bits 0 through 9. Bit 0 being LSB.
 */

/* 601 Video Matrix (standard 601 conversion) */
#define B2R2_VMX0_BGR_TO_YUV_601_VIDEO 0xfd7e4883
#define B2R2_VMX1_BGR_TO_YUV_601_VIDEO 0x03a2584c
#define B2R2_VMX2_BGR_TO_YUV_601_VIDEO 0x107ea7d4
#define B2R2_VMX3_BGR_TO_YUV_601_VIDEO 0x08000080

/* 601 Gfx Matrix (full range conversion) */
#define B2R2_VMX0_BGR_TO_YUV_601_GFX 0xfdde8870
#define B2R2_VMX1_BGR_TO_YUV_601_GFX 0x03220442
#define B2R2_VMX2_BGR_TO_YUV_601_GFX 0x0e3ed7da
#define B2R2_VMX3_BGR_TO_YUV_601_GFX 0x08004080

/* 709 Video Matrix (standard 709 conversion) */
#define B2R2_VMX0_BGR_TO_YUV_709_VIDEO 0xfe9e2483
#define B2R2_VMX1_BGR_TO_YUV_709_VIDEO 0x0262dc37
#define B2R2_VMX2_BGR_TO_YUV_709_VIDEO 0x107e6fe2
#define B2R2_VMX3_BGR_TO_YUV_709_VIDEO 0x08000080

/* 709 Gfx Matrix (standard 709 conversion) */
#define B2R2_VMX0_BGR_TO_YUV_709_GFX 0xfebe6871
#define B2R2_VMX1_BGR_TO_YUV_709_GFX 0x0202742f
#define B2R2_VMX2_BGR_TO_YUV_709_GFX 0x0e3ea7e6
#define B2R2_VMX3_BGR_TO_YUV_709_GFX 0x08004080


/* VMX register values for YUV to BGR conversion */
/*  Note: All YUV -> BGR values are constructed
 * from the YUV -> RGB ones, by swapping
 * first and third rows in the matrix
 * (VMX0 and VMX2 values). Further, the first and
 * third values in the offset vector need to be
 * swapped as well, i.e. bits 0 through 9 are swapped
 * with bits 20 through 29 in the VMX3 value.
 * Bit 0 being LSB.
 */

/* 601 Video Matrix (standard 601 conversion) */
#define B2R2_VMX0_YUV_TO_BGR_601_VIDEO 0x0004013f
#define B2R2_VMX1_YUV_TO_BGR_601_VIDEO 0xe9a403aa
#define B2R2_VMX2_YUV_TO_BGR_601_VIDEO 0x2c440000
#define B2R2_VMX3_YUV_TO_BGR_601_VIDEO 0x3222134f

/* 601 Gfx Matrix (full range conversion) */
#define B2R2_VMX0_YUV_TO_BGR_601_GFX 0x0004a957
#define B2R2_VMX1_YUV_TO_BGR_601_GFX 0xe604ab9c
#define B2R2_VMX2_YUV_TO_BGR_601_GFX 0x3324a800
#define B2R2_VMX3_YUV_TO_BGR_601_GFX 0x2eb21f21

/* 709 Video Matrix (standard 709 conversion) */
#define B2R2_VMX0_YUV_TO_BGR_709_VIDEO 0x00040145
#define B2R2_VMX1_YUV_TO_BGR_709_VIDEO 0xf16403d1
#define B2R2_VMX2_YUV_TO_BGR_709_VIDEO 0x31440000
#define B2R2_VMX3_YUV_TO_BGR_709_VIDEO 0x31814b3b

/* 709 Gfx Matrix (standard 709 conversion) */
#define B2R2_VMX0_YUV_TO_BGR_709_GFX 0x0004a95f
#define B2R2_VMX1_YUV_TO_BGR_709_GFX 0xef04abc9
#define B2R2_VMX2_YUV_TO_BGR_709_GFX 0x3964a800
#define B2R2_VMX3_YUV_TO_BGR_709_GFX 0x2df13307


/* VMX register values for YVU to RGB conversion */

/* 601 Video Matrix (standard 601 conversion) */
#define B2R2_VMX0_YVU_TO_RGB_601_VIDEO 0x00040120
#define B2R2_VMX1_YVU_TO_RGB_601_VIDEO 0xF544034D
#define B2R2_VMX2_YVU_TO_RGB_601_VIDEO 0x37840000
#define B2R2_VMX3_YVU_TO_RGB_601_VIDEO 0x34f21322

/* VMX register values for RGB to YVU conversion */

/* 601 Video Matrix (standard 601 conversion) */
#define B2R2_VMX0_RGB_TO_YVU_601_VIDEO 0xfa9ea483
#define B2R2_VMX1_RGB_TO_YVU_601_VIDEO 0x0982581d
#define B2R2_VMX2_RGB_TO_YVU_601_VIDEO 0x107e4beb
#define B2R2_VMX3_RGB_TO_YVU_601_VIDEO 0x08000080

/* VMX register values for YVU to BGR conversion */

/* 601 Video Matrix (standard 601 conversion) */
#define B2R2_VMX0_YVU_TO_BGR_601_VIDEO 0x37840000
#define B2R2_VMX1_YVU_TO_BGR_601_VIDEO 0xF544034D
#define B2R2_VMX2_YVU_TO_BGR_601_VIDEO 0x00040120
#define B2R2_VMX3_YVU_TO_BGR_601_VIDEO 0x3222134F

/* VMX register values for BGR to YVU conversion */

/* 601 Video Matrix (standard 601 conversion) */
#define B2R2_VMX0_BGR_TO_YVU_601_VIDEO 0x107ea7d4
#define B2R2_VMX1_BGR_TO_YVU_601_VIDEO 0x03a2584c
#define B2R2_VMX2_BGR_TO_YVU_601_VIDEO 0xfd7e4883
#define B2R2_VMX3_BGR_TO_YVU_601_VIDEO 0x08000080

/* VMX register values for YVU to YUV conversion */

/* 601 Video Matrix (standard 601 conversion) */
/* Internally, the components are in fact stored
 * with luma in the middle, i.e. UYV, which is why
 * the values are just like for RGB->BGR conversion.
 */
#define B2R2_VMX0_YVU_TO_YUV_601_VIDEO 0x00000100
#define B2R2_VMX1_YVU_TO_YUV_601_VIDEO 0x00040000
#define B2R2_VMX2_YVU_TO_YUV_601_VIDEO 0x20000000
#define B2R2_VMX3_YVU_TO_YUV_601_VIDEO 0x00000000

/* VMX register values for RGB to BLT_YUV888 conversion */

/* 601 Video Matrix (standard 601 conversion) */
/*
 * BLT_YUV888 has color components laid out in memory as V, U, Y, (Alpha)
 * with V at the first byte (due to little endian addressing).
 * B2R2 expects them to be as U, Y, V, (A)
 * with U at the first byte.
 * Note: RGB -> BLT_YUV888 values are calculated by multiplying
 * the RGB -> YUV matrix [A], with [S] to form [S]x[A] where
 *     |0 1 0|
 * S = |0 0 1|
 *     |1 0 0|
 * Essentially changing the order of rows in the original
 * matrix [A].
 * row1 -> row3
 * row2 -> row1
 * row3 -> row2
 * Values in the offset vector are swapped in the same manner.
 */
#define B2R2_VMX0_RGB_TO_BLT_YUV888_601_VIDEO 0x0982581d
#define B2R2_VMX1_RGB_TO_BLT_YUV888_601_VIDEO 0xfa9ea483
#define B2R2_VMX2_RGB_TO_BLT_YUV888_601_VIDEO 0x107e4beb
#define B2R2_VMX3_RGB_TO_BLT_YUV888_601_VIDEO 0x00020080

/* VMX register values for BLT_YUV888 to RGB conversion */

/*
 * Note: BLT_YUV888 -> RGB values are calculated by multiplying
 * the YUV -> RGB matrix [A], with [S] to form [A]x[S] where
 *     |0 0 1|
 * S = |1 0 0|
 *     |0 1 0|
 * Essentially changing the order of columns in the original
 * matrix [A].
 * col1 -> col3
 * col2 -> col1
 * col3 -> col2
 * Values in the offset vector remain unchanged.
 */
#define B2R2_VMX0_BLT_YUV888_TO_RGB_601_VIDEO 0x20000121
#define B2R2_VMX1_BLT_YUV888_TO_RGB_601_VIDEO 0x201ea74c
#define B2R2_VMX2_BLT_YUV888_TO_RGB_601_VIDEO 0x2006f000
#define B2R2_VMX3_BLT_YUV888_TO_RGB_601_VIDEO 0x34f21322

/* VMX register values for YUV to BLT_YUV888 conversion */
#define B2R2_VMX0_YUV_TO_BLT_YUV888 0x00040000
#define B2R2_VMX1_YUV_TO_BLT_YUV888 0x00000100
#define B2R2_VMX2_YUV_TO_BLT_YUV888 0x20000000
#define B2R2_VMX3_YUV_TO_BLT_YUV888 0x00000000

/* VMX register values for BLT_YUV888 to YUV conversion */
#define B2R2_VMX0_BLT_YUV888_TO_YUV 0x00000100
#define B2R2_VMX1_BLT_YUV888_TO_YUV 0x20000000
#define B2R2_VMX2_BLT_YUV888_TO_YUV 0x00040000
#define B2R2_VMX3_BLT_YUV888_TO_YUV 0x00000000

/* VMX register values for YVU to BLT_YUV888 conversion */
#define B2R2_VMX0_YVU_TO_BLT_YUV888 0x00040000
#define B2R2_VMX1_YVU_TO_BLT_YUV888 0x20000000
#define B2R2_VMX2_YVU_TO_BLT_YUV888 0x00000100
#define B2R2_VMX3_YVU_TO_BLT_YUV888 0x00000000

/* VMX register values for BLT_YUV888 to YVU conversion */
#define B2R2_VMX0_BLT_YUV888_TO_YVU 0x00040000
#define B2R2_VMX1_BLT_YUV888_TO_YVU 0x20000000
#define B2R2_VMX2_BLT_YUV888_TO_YVU 0x00000100
#define B2R2_VMX3_BLT_YUV888_TO_YVU 0x00000000

#endif /* B2R2_HW_H__ */
