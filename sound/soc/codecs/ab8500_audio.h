/*
 * Copyright (C) ST-Ericsson SA 2010
 *
 * Author: Mikko J. Lehto <mikko.lehto@symbio.com>,
 *         Mikko Sarmanne <mikko.sarmanne@symbio.com>,
 *         Ola Lilja <ola.o.lilja@stericsson.com>
 *         for ST-Ericsson.
 *
 * License terms:
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation.
 */

#ifndef AB8500_CODEC_REGISTERS_H
#define AB8500_CODEC_REGISTERS_H

#define AB8500_SUPPORTED_RATE (SNDRV_PCM_RATE_48000)
#define AB8500_SUPPORTED_FMT (SNDRV_PCM_FMTBIT_S16_LE)

extern struct snd_soc_dai_driver ab8500_codec_dai[];
extern struct snd_soc_codec_driver soc_codec_dev_ab8500;

/* Extended interface for codec-driver */

int ab8500_audio_power_control(bool power_on);
int ab8500_audio_set_word_length(struct snd_soc_dai *dai, unsigned int wl);
int ab8500_audio_set_bit_delay(struct snd_soc_dai *dai, unsigned int delay);
int ab8500_audio_setup_if1(struct snd_soc_codec *codec,
			unsigned int fmt,
			unsigned int wl,
			unsigned int delay);
unsigned int ab8500_audio_anc_status(void);
int ab8500_audio_anc_configure(unsigned int req_state);

enum ab8500_audio_dapm_path {
	AB8500_AUDIO_DAPM_PATH_DMIC,
	AB8500_AUDIO_DAPM_PATH_AMIC1,
	AB8500_AUDIO_DAPM_PATH_AMIC2
};
bool ab8500_audio_dapm_path_active(enum ab8500_audio_dapm_path dapm_path);

enum ab8500_audio_adcm {
	AB8500_AUDIO_ADCM_NORMAL,
	AB8500_AUDIO_ADCM_FORCE_UP,
	AB8500_AUDIO_ADCM_FORCE_DOWN
};
int ab8500_audio_set_adcm(enum ab8500_audio_adcm req_adcm);

#define SOC_SINGLE_VALUE_S1R(xreg0, xcount, xmin, xmax, xinvert) \
	((unsigned long)&(struct soc_smra_control) \
	{ .reg = ((unsigned int[]){ xreg0 }), \
	.rcount = 1, .count = xcount, \
	.invert = xinvert, .min = xmin, .max = xmax})

#define SOC_SINGLE_VALUE_S2R(xreg0, xreg1, xcount, xmin, xmax, xinvert) \
	((unsigned long)&(struct soc_smra_control) \
	{.reg = ((unsigned int[]){ xreg0, xreg1 }), \
	.rcount = 2, .count = xcount, \
	.min = xmin, .max = xmax, .invert = xinvert})

#define SOC_SINGLE_VALUE_S4R(xreg0, xreg1, xreg2, xreg3, \
	xcount, xmin, xmax, xinvert) \
	((unsigned long)&(struct soc_smra_control) \
	{.reg = ((unsigned int[]){ xreg0, xreg1, xreg2, xreg3 }), \
	.rcount = 4, .count = xcount, \
	.min = xmin, .max = xmax, .invert = xinvert})

#define SOC_SINGLE_VALUE_S8R(xreg0, xreg1, xreg2, xreg3, \
		xreg4, xreg5, xreg6, xreg7, xcount, xmin, xmax, xinvert) \
	((unsigned long)&(struct soc_smra_control) \
	{.reg = ((unsigned int[]){ xreg0, xreg1, xreg2, xreg3, \
			xreg4, xreg5, xreg6, xreg7 }), \
	.rcount = 8, .count = xcount, \
	.min = xmin, .max = xmax, .invert = xinvert})

#define SOC_MULTIPLE_VALUE_SA(xvalues, xcount, xmin, xmax, xinvert) \
	((unsigned long)&(struct soc_smra_control) \
	{.values = xvalues, .rcount = 1, .count = xcount, \
	.min = xmin, .max = xmax, .invert = xinvert})

#define SOC_ENUM_STROBE_DECL(name, xreg, xbit, xinvert, xtexts) \
	struct soc_enum name = SOC_ENUM_DOUBLE(xreg, xbit, \
	xinvert, 2, xtexts)

/* Extended SOC macros */

#define SOC_SINGLE_S1R(xname, reg0, min, max, invert) \
{	.iface = SNDRV_CTL_ELEM_IFACE_MIXER, .name = xname, \
	.access = SNDRV_CTL_ELEM_ACCESS_READWRITE, \
	.info = snd_soc_info_s, .get = snd_soc_get_smr, .put = snd_soc_put_smr, \
	.private_value =  SOC_SINGLE_VALUE_S1R(reg0, 1, min, max, invert) }

#define SOC_SINGLE_S2R(xname, reg0, reg1, min, max, invert) \
{	.iface = SNDRV_CTL_ELEM_IFACE_MIXER, .name = xname, \
	.access = SNDRV_CTL_ELEM_ACCESS_READWRITE, \
	.info = snd_soc_info_s, .get = snd_soc_get_smr, .put = snd_soc_put_smr, \
	.private_value =  SOC_SINGLE_VALUE_S2R(reg0, reg1, 1, min, max, invert) }

#define SOC_SINGLE_S4R(xname, reg0, reg1, reg2, reg3, min, max, invert) \
{	.iface = SNDRV_CTL_ELEM_IFACE_MIXER, .name = xname, \
	.access = SNDRV_CTL_ELEM_ACCESS_READWRITE, \
	.info = snd_soc_info_s, .get = snd_soc_get_smr, .put = snd_soc_put_smr, \
	.private_value =  SOC_SINGLE_VALUE_S4R(reg0, reg1, reg2, reg3, \
	1, min, max, invert) }

#define SOC_SINGLE_S8R(xname, reg0, reg1, reg2, reg3, \
		reg4, reg5, reg6, reg7, min, max, invert) \
{	.iface = SNDRV_CTL_ELEM_IFACE_MIXER, .name = xname, \
	.access = SNDRV_CTL_ELEM_ACCESS_READWRITE, \
	.info = snd_soc_info_s, .get = snd_soc_get_smr, .put = snd_soc_put_smr, \
	.private_value =  SOC_SINGLE_VALUE_S4R(reg0, reg1, reg2, reg3, \
			reg4, reg5, reg6, reg7\
	1, min, max, invert) }

#define SOC_MULTIPLE_SA(xname, values, min, max, invert) \
{	.iface = SNDRV_CTL_ELEM_IFACE_MIXER, .name = xname, \
	.access = SNDRV_CTL_ELEM_ACCESS_READWRITE, \
	.info = snd_soc_info_s, .get = snd_soc_get_sa, .put = snd_soc_put_sa, \
	.private_value = SOC_MULTIPLE_VALUE_SA(values, ARRAY_SIZE(values), \
	min, max, invert) }

#define SOC_ENUM_STROBE(xname, xenum) \
	SOC_ENUM_EXT(xname, xenum, \
	snd_soc_get_enum_strobe, \
	snd_soc_put_enum_strobe)

/* AB8500 audio bank (0x0d) register definitions */

#define REG_POWERUP		0x00
#define REG_AUDSWRESET		0x01
#define REG_ADPATHENA		0x02
#define REG_DAPATHENA		0x03
#define REG_ANACONF1		0x04
#define REG_ANACONF2		0x05
#define REG_DIGMICCONF		0x06
#define REG_ANACONF3		0x07
#define REG_ANACONF4		0x08
#define REG_DAPATHCONF		0x09
#define REG_MUTECONF		0x0A
#define REG_SHORTCIRCONF	0x0B
#define REG_ANACONF5		0x0C
#define REG_ENVCPCONF		0x0D
#define REG_SIGENVCONF		0x0E
#define REG_PWMGENCONF1		0x0F
#define REG_PWMGENCONF2		0x10
#define REG_PWMGENCONF3		0x11
#define REG_PWMGENCONF4		0x12
#define REG_PWMGENCONF5		0x13
#define REG_ANAGAIN1		0x14
#define REG_ANAGAIN2		0x15
#define REG_ANAGAIN3		0x16
#define REG_ANAGAIN4		0x17
#define REG_DIGLINHSLGAIN	0x18
#define REG_DIGLINHSRGAIN	0x19
#define REG_ADFILTCONF		0x1A
#define REG_DIGIFCONF1		0x1B
#define REG_DIGIFCONF2		0x1C
#define REG_DIGIFCONF3		0x1D
#define REG_DIGIFCONF4		0x1E
#define REG_ADSLOTSEL1		0x1F
#define REG_ADSLOTSEL2		0x20
#define REG_ADSLOTSEL3		0x21
#define REG_ADSLOTSEL4		0x22
#define REG_ADSLOTSEL5		0x23
#define REG_ADSLOTSEL6		0x24
#define REG_ADSLOTSEL7		0x25
#define REG_ADSLOTSEL8		0x26
#define REG_ADSLOTSEL9		0x27
#define REG_ADSLOTSEL10		0x28
#define REG_ADSLOTSEL11		0x29
#define REG_ADSLOTSEL12		0x2A
#define REG_ADSLOTSEL13		0x2B
#define REG_ADSLOTSEL14		0x2C
#define REG_ADSLOTSEL15		0x2D
#define REG_ADSLOTSEL16		0x2E
#define REG_ADSLOTHIZCTRL1	0x2F
#define REG_ADSLOTHIZCTRL2	0x30
#define REG_ADSLOTHIZCTRL3	0x31
#define REG_ADSLOTHIZCTRL4	0x32
#define REG_DASLOTCONF1		0x33
#define REG_DASLOTCONF2		0x34
#define REG_DASLOTCONF3		0x35
#define REG_DASLOTCONF4		0x36
#define REG_DASLOTCONF5		0x37
#define REG_DASLOTCONF6		0x38
#define REG_DASLOTCONF7		0x39
#define REG_DASLOTCONF8		0x3A
#define REG_CLASSDCONF1		0x3B
#define REG_CLASSDCONF2		0x3C
#define REG_CLASSDCONF3		0x3D
#define REG_DMICFILTCONF	0x3E
#define REG_DIGMULTCONF1	0x3F
#define REG_DIGMULTCONF2	0x40
#define REG_ADDIGGAIN1		0x41
#define REG_ADDIGGAIN2		0x42
#define REG_ADDIGGAIN3		0x43
#define REG_ADDIGGAIN4		0x44
#define REG_ADDIGGAIN5		0x45
#define REG_ADDIGGAIN6		0x46
#define REG_DADIGGAIN1		0x47
#define REG_DADIGGAIN2		0x48
#define REG_DADIGGAIN3		0x49
#define REG_DADIGGAIN4		0x4A
#define REG_DADIGGAIN5		0x4B
#define REG_DADIGGAIN6		0x4C
#define REG_ADDIGLOOPGAIN1	0x4D
#define REG_ADDIGLOOPGAIN2	0x4E
#define REG_HSLEARDIGGAIN	0x4F
#define REG_HSRDIGGAIN		0x50
#define REG_SIDFIRGAIN1		0x51
#define REG_SIDFIRGAIN2		0x52
#define REG_ANCCONF1		0x53
#define REG_ANCCONF2		0x54
#define REG_ANCCONF3		0x55
#define REG_ANCCONF4		0x56
#define REG_ANCCONF5		0x57
#define REG_ANCCONF6		0x58
#define REG_ANCCONF7		0x59
#define REG_ANCCONF8		0x5A
#define REG_ANCCONF9		0x5B
#define REG_ANCCONF10		0x5C
#define REG_ANCCONF11		0x5D
#define REG_ANCCONF12		0x5E
#define REG_ANCCONF13		0x5F
#define REG_ANCCONF14		0x60
#define REG_SIDFIRADR		0x61
#define REG_SIDFIRCOEF1		0x62
#define REG_SIDFIRCOEF2		0x63
#define REG_SIDFIRCONF		0x64
#define REG_AUDINTMASK1		0x65
#define REG_AUDINTSOURCE1	0x66
#define REG_AUDINTMASK2		0x67
#define REG_AUDINTSOURCE2	0x68
#define REG_FIFOCONF1		0x69
#define REG_FIFOCONF2		0x6A
#define REG_FIFOCONF3		0x6B
#define REG_FIFOCONF4		0x6C
#define REG_FIFOCONF5		0x6D
#define REG_FIFOCONF6		0x6E
#define REG_AUDREV		0x6F

#define AB8500_FIRST_REG	REG_POWERUP
#define AB8500_LAST_REG		REG_AUDREV
#define AB8500_CACHEREGNUM	(AB8500_LAST_REG + 1)


#define REG_MASK_ALL				0xFF
#define REG_MASK_NONE				0x00

/* REG_POWERUP */
#define REG_POWERUP_POWERUP			7
#define REG_POWERUP_ENANA			3

/* REG_AUDSWRESET */
#define REG_AUDSWRESET_SWRESET			7

/* REG_ADPATHENA */
#define REG_ADPATHENA_ENAD12			7
#define REG_ADPATHENA_ENAD34			5
#define REG_ADPATHENA_ENAD5768			3

/* REG_DAPATHENA */
#define REG_DAPATHENA_ENDA1			7
#define REG_DAPATHENA_ENDA2			6
#define REG_DAPATHENA_ENDA3			5
#define REG_DAPATHENA_ENDA4			4
#define REG_DAPATHENA_ENDA5			3
#define REG_DAPATHENA_ENDA6			2

/* REG_ANACONF1 */
#define REG_ANACONF1_HSLOWPOW			7
#define REG_ANACONF1_DACLOWPOW1			6
#define REG_ANACONF1_DACLOWPOW0			5
#define REG_ANACONF1_EARDACLOWPOW		4
#define REG_ANACONF1_EARSELCM			2
#define REG_ANACONF1_HSHPEN			1
#define REG_ANACONF1_EARDRVLOWPOW		0

/* REG_ANACONF2 */
#define REG_ANACONF2_ENMIC1			7
#define REG_ANACONF2_ENMIC2			6
#define REG_ANACONF2_ENLINL			5
#define REG_ANACONF2_ENLINR			4
#define REG_ANACONF2_MUTMIC1			3
#define REG_ANACONF2_MUTMIC2			2
#define REG_ANACONF2_MUTLINL			1
#define REG_ANACONF2_MUTLINR			0

/* REG_DIGMICCONF */
#define REG_DIGMICCONF_ENDMIC1			7
#define REG_DIGMICCONF_ENDMIC2			6
#define REG_DIGMICCONF_ENDMIC3			5
#define REG_DIGMICCONF_ENDMIC4			4
#define REG_DIGMICCONF_ENDMIC5			3
#define REG_DIGMICCONF_ENDMIC6			2
#define REG_DIGMICCONF_HSFADSPEED		0

/* REG_ANACONF3 */
#define REG_ANACONF3_MIC1SEL			7
#define REG_ANACONF3_LINRSEL			6
#define REG_ANACONF3_ENDRVHSL			5
#define REG_ANACONF3_ENDRVHSR			4
#define REG_ANACONF3_ENADCMIC			2
#define REG_ANACONF3_ENADCLINL			1
#define REG_ANACONF3_ENADCLINR			0

/* REG_ANACONF4 */
#define REG_ANACONF4_DISPDVSS			7
#define REG_ANACONF4_ENEAR			6
#define REG_ANACONF4_ENHSL			5
#define REG_ANACONF4_ENHSR			4
#define REG_ANACONF4_ENHFL			3
#define REG_ANACONF4_ENHFR			2
#define REG_ANACONF4_ENVIB1			1
#define REG_ANACONF4_ENVIB2			0

/* REG_DAPATHCONF */
#define REG_DAPATHCONF_ENDACEAR			6
#define REG_DAPATHCONF_ENDACHSL			5
#define REG_DAPATHCONF_ENDACHSR			4
#define REG_DAPATHCONF_ENDACHFL			3
#define REG_DAPATHCONF_ENDACHFR			2
#define REG_DAPATHCONF_ENDACVIB1		1
#define REG_DAPATHCONF_ENDACVIB2		0

/* REG_MUTECONF */
#define REG_MUTECONF_MUTEAR			6
#define REG_MUTECONF_MUTHSL			5
#define REG_MUTECONF_MUTHSR			4
#define REG_MUTECONF_MUTDACEAR			2
#define REG_MUTECONF_MUTDACHSL			1
#define REG_MUTECONF_MUTDACHSR			0


/* REG_SHORTCIRCONF */

/* REG_ANACONF5 */
#define REG_ANACONF5_ENCPHS			7
#define REG_ANACONF5_HSLDACTOLOL		5
#define REG_ANACONF5_HSRDACTOLOR		4
#define REG_ANACONF5_ENLOL			3
#define REG_ANACONF5_ENLOR			2
#define REG_ANACONF5_HSAUTOEN			0

/* REG_ENVCPCONF */
#define REG_ENVCPCONF_ENVDETHTHRE		4
#define REG_ENVCPCONF_ENVDETLTHRE		0
#define REG_ENVCPCONF_ENVDETHTHRE_MAX		0x0F
#define REG_ENVCPCONF_ENVDETLTHRE_MAX		0x0F

/* REG_SIGENVCONF */
#define REG_SIGENVCONF_CPLVEN			5
#define REG_SIGENVCONF_ENVDETCPEN		4
#define REG_SIGENVCONF_ENVDETTIME		0
#define REG_SIGENVCONF_ENVDETTIME_MAX		0x0F

/* REG_PWMGENCONF1 */
#define REG_PWMGENCONF1_PWMTOVIB1		7
#define REG_PWMGENCONF1_PWMTOVIB2		6
#define REG_PWMGENCONF1_PWM1CTRL		5
#define REG_PWMGENCONF1_PWM2CTRL		4
#define REG_PWMGENCONF1_PWM1NCTRL		3
#define REG_PWMGENCONF1_PWM1PCTRL		2
#define REG_PWMGENCONF1_PWM2NCTRL		1
#define REG_PWMGENCONF1_PWM2PCTRL		0

/* REG_PWMGENCONF2 */
/* REG_PWMGENCONF3 */
/* REG_PWMGENCONF4 */
/* REG_PWMGENCONF5 */
#define REG_PWMGENCONFX_PWMVIBXPOL		7
#define REG_PWMGENCONFX_PWMVIBXDUTCYC		0
#define REG_PWMGENCONFX_PWMVIBXDUTCYC_MAX	0x64

/* REG_ANAGAIN1 */
/* REG_ANAGAIN2 */
#define REG_ANAGAINX_ENSEMICX			7
#define REG_ANAGAINX_LOWPOWMICX			6
#define REG_ANAGAINX_MICXGAIN			0
#define REG_ANAGAINX_MICXGAIN_MAX		0x1F

/* REG_ANAGAIN3 */
#define REG_ANAGAIN3_HSLGAIN			4
#define REG_ANAGAIN3_HSRGAIN			0
#define REG_ANAGAIN3_HSXGAIN_MAX		0x0F

/* REG_ANAGAIN4 */
#define REG_ANAGAIN4_LINLGAIN			4
#define REG_ANAGAIN4_LINRGAIN			0
#define REG_ANAGAIN4_LINXGAIN_MAX		0x0F

/* REG_DIGLINHSLGAIN */
/* REG_DIGLINHSRGAIN */
#define REG_DIGLINHSXGAIN_LINTOHSXGAIN		0
#define REG_DIGLINHSXGAIN_LINTOHSXGAIN_MAX	0x13

/* REG_ADFILTCONF */
#define REG_ADFILTCONF_AD1NH			7
#define REG_ADFILTCONF_AD2NH			6
#define REG_ADFILTCONF_AD3NH			5
#define REG_ADFILTCONF_AD4NH			4
#define REG_ADFILTCONF_AD1VOICE			3
#define REG_ADFILTCONF_AD2VOICE			2
#define REG_ADFILTCONF_AD3VOICE			1
#define REG_ADFILTCONF_AD4VOICE			0

/* REG_DIGIFCONF1 */
#define REG_DIGIFCONF1_ENMASTGEN		7
#define REG_DIGIFCONF1_IF1BITCLKOS1		6
#define REG_DIGIFCONF1_IF1BITCLKOS0		5
#define REG_DIGIFCONF1_ENFSBITCLK1		4
#define REG_DIGIFCONF1_IF0BITCLKOS1		2
#define REG_DIGIFCONF1_IF0BITCLKOS0		1
#define REG_DIGIFCONF1_ENFSBITCLK0		0

/* REG_DIGIFCONF2 */
#define REG_DIGIFCONF2_FSYNC0P			6
#define REG_DIGIFCONF2_BITCLK0P			5
#define REG_DIGIFCONF2_IF0DEL			4
#define REG_DIGIFCONF2_IF0FORMAT1		3
#define REG_DIGIFCONF2_IF0FORMAT0		2
#define REG_DIGIFCONF2_IF0WL1			1
#define REG_DIGIFCONF2_IF0WL0			0

/* REG_DIGIFCONF3 */
#define REG_DIGIFCONF3_IF0DATOIF1AD		7
#define REG_DIGIFCONF3_IF0CLKTOIF1CLK		6
#define REG_DIGIFCONF3_IF1MASTER		5
#define REG_DIGIFCONF3_IF1DATOIF0AD		3
#define REG_DIGIFCONF3_IF1CLKTOIF0CLK		2
#define REG_DIGIFCONF3_IF0MASTER		1
#define REG_DIGIFCONF3_IF0BFIFOEN		0

/* REG_DIGIFCONF4 */
#define REG_DIGIFCONF4_FSYNC1P			6
#define REG_DIGIFCONF4_BITCLK1P			5
#define REG_DIGIFCONF4_IF1DEL			4
#define REG_DIGIFCONF4_IF1FORMAT1		3
#define REG_DIGIFCONF4_IF1FORMAT0		2
#define REG_DIGIFCONF4_IF1WL1			1
#define REG_DIGIFCONF4_IF1WL0			0

/* REG_ADSLOTSELX */
#define REG_ADSLOTSELX_AD_OUT1_TO_SLOT_ODD	0x00
#define REG_ADSLOTSELX_AD_OUT2_TO_SLOT_ODD	0x01
#define REG_ADSLOTSELX_AD_OUT3_TO_SLOT_ODD	0x02
#define REG_ADSLOTSELX_AD_OUT4_TO_SLOT_ODD	0x03
#define REG_ADSLOTSELX_AD_OUT5_TO_SLOT_ODD	0x04
#define REG_ADSLOTSELX_AD_OUT6_TO_SLOT_ODD	0x05
#define REG_ADSLOTSELX_AD_OUT7_TO_SLOT_ODD	0x06
#define REG_ADSLOTSELX_AD_OUT8_TO_SLOT_ODD	0x07
#define REG_ADSLOTSELX_ZEROES_TO_SLOT_ODD	0x08
#define REG_ADSLOTSELX_TRISTATE_TO_SLOT_ODD	0x0F
#define REG_ADSLOTSELX_AD_OUT1_TO_SLOT_EVEN	0x00
#define REG_ADSLOTSELX_AD_OUT2_TO_SLOT_EVEN	0x10
#define REG_ADSLOTSELX_AD_OUT3_TO_SLOT_EVEN	0x20
#define REG_ADSLOTSELX_AD_OUT4_TO_SLOT_EVEN	0x30
#define REG_ADSLOTSELX_AD_OUT5_TO_SLOT_EVEN	0x40
#define REG_ADSLOTSELX_AD_OUT6_TO_SLOT_EVEN	0x50
#define REG_ADSLOTSELX_AD_OUT7_TO_SLOT_EVEN	0x60
#define REG_ADSLOTSELX_AD_OUT8_TO_SLOT_EVEN	0x70
#define REG_ADSLOTSELX_ZEROES_TO_SLOT_EVEN	0x80
#define REG_ADSLOTSELX_TRISTATE_TO_SLOT_EVEN	0xF0
#define REG_ADSLOTSELX_EVEN_SHIFT		0
#define REG_ADSLOTSELX_ODD_SHIFT		4

/* REG_ADSLOTHIZCTRL1 */
/* REG_ADSLOTHIZCTRL2 */
/* REG_ADSLOTHIZCTRL3 */
/* REG_ADSLOTHIZCTRL4 */
/* REG_DASLOTCONF1 */
#define REG_DASLOTCONF1_DA12VOICE		7
#define REG_DASLOTCONF1_SWAPDA12_34		6
#define REG_DASLOTCONF1_DAI7TOADO1		5

/* REG_DASLOTCONF2 */
#define REG_DASLOTCONF2_DAI8TOADO2		5

/* REG_DASLOTCONF3 */
#define REG_DASLOTCONF3_DA34VOICE		7
#define REG_DASLOTCONF3_DAI7TOADO3		5

/* REG_DASLOTCONF4 */
#define REG_DASLOTCONF4_DAI8TOADO4		5

/* REG_DASLOTCONF5 */
#define REG_DASLOTCONF5_DA56VOICE		7
#define REG_DASLOTCONF5_DAI7TOADO5		5

/* REG_DASLOTCONF6 */
#define REG_DASLOTCONF6_DAI8TOADO6		5

/* REG_DASLOTCONF7 */
#define REG_DASLOTCONF7_DAI8TOADO7		5

/* REG_DASLOTCONF8 */
#define REG_DASLOTCONF8_DAI7TOADO8		5

#define REG_DASLOTCONFX_SLTODAX_SHIFT		0
#define REG_DASLOTCONFX_SLTODAX_MASK		0x1F

/* REG_CLASSDCONF1 */
#define REG_CLASSDCONF1_PARLHF			7
#define REG_CLASSDCONF1_PARLVIB			6
#define REG_CLASSDCONF1_VIB1SWAPEN		3
#define REG_CLASSDCONF1_VIB2SWAPEN		2
#define REG_CLASSDCONF1_HFLSWAPEN		1
#define REG_CLASSDCONF1_HFRSWAPEN		0

/* REG_CLASSDCONF2 */
#define REG_CLASSDCONF2_FIRBYP3			7
#define REG_CLASSDCONF2_FIRBYP2			6
#define REG_CLASSDCONF2_FIRBYP1			5
#define REG_CLASSDCONF2_FIRBYP0			4
#define REG_CLASSDCONF2_HIGHVOLEN3		3
#define REG_CLASSDCONF2_HIGHVOLEN2		2
#define REG_CLASSDCONF2_HIGHVOLEN1		1
#define REG_CLASSDCONF2_HIGHVOLEN0		0

/* REG_CLASSDCONF3 */
#define REG_CLASSDCONF3_DITHHPGAIN		4
#define REG_CLASSDCONF3_DITHHPGAIN_MAX		0x0A
#define REG_CLASSDCONF3_DITHWGAIN		0
#define REG_CLASSDCONF3_DITHWGAIN_MAX		0x0A

/* REG_DMICFILTCONF */
#define REG_DMICFILTCONF_ANCINSEL		7
#define REG_DMICFILTCONF_DA3TOEAR		6
#define REG_DMICFILTCONF_DMIC1SINC3		5
#define REG_DMICFILTCONF_DMIC2SINC3		4
#define REG_DMICFILTCONF_DMIC3SINC3		3
#define REG_DMICFILTCONF_DMIC4SINC3		2
#define REG_DMICFILTCONF_DMIC5SINC3		1
#define REG_DMICFILTCONF_DMIC6SINC3		0

/* REG_DIGMULTCONF1 */
#define REG_DIGMULTCONF1_DATOHSLEN		7
#define REG_DIGMULTCONF1_DATOHSREN		6
#define REG_DIGMULTCONF1_AD1SEL			5
#define REG_DIGMULTCONF1_AD2SEL			4
#define REG_DIGMULTCONF1_AD3SEL			3
#define REG_DIGMULTCONF1_AD5SEL			2
#define REG_DIGMULTCONF1_AD6SEL			1
#define REG_DIGMULTCONF1_ANCSEL			0

/* REG_DIGMULTCONF2 */
#define REG_DIGMULTCONF2_DATOHFREN		7
#define REG_DIGMULTCONF2_DATOHFLEN		6
#define REG_DIGMULTCONF2_HFRSEL			5
#define REG_DIGMULTCONF2_HFLSEL			4
#define REG_DIGMULTCONF2_FIRSID1SEL		2
#define REG_DIGMULTCONF2_FIRSID2SEL		0

/* REG_ADDIGGAIN1 */
/* REG_ADDIGGAIN2 */
/* REG_ADDIGGAIN3 */
/* REG_ADDIGGAIN4 */
/* REG_ADDIGGAIN5 */
/* REG_ADDIGGAIN6 */
#define REG_ADDIGGAINX_FADEDISADX		6
#define REG_ADDIGGAINX_ADXGAIN_MAX		0x3F

/* REG_DADIGGAIN1 */
/* REG_DADIGGAIN2 */
/* REG_DADIGGAIN3 */
/* REG_DADIGGAIN4 */
/* REG_DADIGGAIN5 */
/* REG_DADIGGAIN6 */
#define REG_DADIGGAINX_FADEDISDAX		6
#define REG_DADIGGAINX_DAXGAIN_MAX		0x3F

/* REG_ADDIGLOOPGAIN1 */
/* REG_ADDIGLOOPGAIN2 */
#define REG_ADDIGLOOPGAINX_FADEDISADXL		6
#define REG_ADDIGLOOPGAINX_ADXLBGAIN_MAX	0x3F

/* REG_HSLEARDIGGAIN */
#define REG_HSLEARDIGGAIN_HSSINC1		7
#define REG_HSLEARDIGGAIN_FADEDISHSL		4
#define REG_HSLEARDIGGAIN_HSLDGAIN_MAX		0x09

/* REG_HSRDIGGAIN */
#define REG_HSRDIGGAIN_FADESPEED		6
#define REG_HSRDIGGAIN_FADEDISHSR		4
#define REG_HSRDIGGAIN_HSRDGAIN_MAX		0x09

/* REG_SIDFIRGAIN1 */
/* REG_SIDFIRGAIN2 */
#define REG_SIDFIRGAINX_FIRSIDXGAIN_MAX		0x1F

/* REG_ANCCONF1 */
#define REG_ANCCONF1_ANCIIRUPDATE		3
#define REG_ANCCONF1_ENANC			2
#define REG_ANCCONF1_ANCIIRINIT			1
#define REG_ANCCONF1_ANCFIRUPDATE		0

/* REG_ANCCONF2 */
#define REG_ANCCONF2_VALUE_MIN			-0x10
#define REG_ANCCONF2_VALUE_MAX			0x0F
/* REG_ANCCONF3 */
#define REG_ANCCONF3_VALUE_MIN			-0x10
#define REG_ANCCONF3_VALUE_MAX			0x0F
/* REG_ANCCONF4 */
#define REG_ANCCONF4_VALUE_MIN			-0x10
#define REG_ANCCONF4_VALUE_MAX			0x0F
/* REG_ANC_FIR_COEFFS */
#define REG_ANC_FIR_COEFF_MIN			-0x8000
#define REG_ANC_FIR_COEFF_MAX			0x7FFF
#define REG_ANC_FIR_COEFFS			0xF
/* REG_ANC_IIR_COEFFS */
#define REG_ANC_IIR_COEFF_MIN			-0x800000
#define REG_ANC_IIR_COEFF_MAX			0x7FFFFF
#define REG_ANC_IIR_COEFFS			0x18
/* REG_ANC_WARP_DELAY */
#define REG_ANC_WARP_DELAY_MIN			0x0000
#define REG_ANC_WARP_DELAY_MAX			0xFFFF
/* REG_ANCCONF11 */
/* REG_ANCCONF12 */
/* REG_ANCCONF13 */
/* REG_ANCCONF14 */

/* REG_SIDFIRADR */
#define REG_SIDFIRADR_FIRSIDSET			7
#define REG_SIDFIRADR_ADDRESS_SHIFT		0
#define REG_SIDFIRADR_ADDRESS_MAX		0x7F

/* REG_SIDFIRCOEF1 */
/* REG_SIDFIRCOEF2 */
#define REG_SIDFIRCOEFX_VALUE_SHIFT		0
#define REG_SIDFIRCOEFX_VALUE_MAX		0xFFFF

/* REG_SIDFIRCONF */
#define REG_SIDFIRCONF_ENFIRSIDS		2
#define REG_SIDFIRCONF_FIRSIDSTOIF1		1
#define REG_SIDFIRCONF_FIRSIDBUSY		0

/* REG_AUDINTMASK1 */
/* REG_AUDINTSOURCE1 */
/* REG_AUDINTMASK2 */
/* REG_AUDINTSOURCE2 */

/* REG_FIFOCONF1 */
#define REG_FIFOCONF1_BFIFOMASK			0x80
#define REG_FIFOCONF1_BFIFO19M2			0x40
#define REG_FIFOCONF1_BFIFOINT_SHIFT		0
#define REG_FIFOCONF1_BFIFOINT_MAX		0x3F

/* REG_FIFOCONF2 */
#define REG_FIFOCONF2_BFIFOTX_SHIFT		0
#define REG_FIFOCONF2_BFIFOTX_MAX		0xFF

/* REG_FIFOCONF3 */
#define REG_FIFOCONF3_BFIFOEXSL_SHIFT		5
#define REG_FIFOCONF3_BFIFOEXSL_MAX		0x5
#define REG_FIFOCONF3_PREBITCLK0_SHIFT		2
#define REG_FIFOCONF3_PREBITCLK0_MAX		0x7
#define REG_FIFOCONF3_BFIFOMAST_SHIFT		1
#define REG_FIFOCONF3_BFIFORUN_SHIFT		0

/* REG_FIFOCONF4 */
#define REG_FIFOCONF4_BFIFOFRAMSW_SHIFT		0
#define REG_FIFOCONF4_BFIFOFRAMSW_MAX		0xFF

/* REG_FIFOCONF5 */
#define REG_FIFOCONF5_BFIFOWAKEUP_SHIFT		0
#define REG_FIFOCONF5_BFIFOWAKEUP_MAX		0xFF

/* REG_FIFOCONF6 */
#define REG_FIFOCONF6_BFIFOSAMPLE_SHIFT		0
#define REG_FIFOCONF6_BFIFOSAMPLE_MAX		0xFF

/* REG_AUDREV */

#endif
