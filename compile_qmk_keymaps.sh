#!/bin/bash
# find all files: "Z:\home\benjamin\qmk_firmware\keyboards\*\nug*\keymap.c"

# 59 lines, 73 total keyboards (missing Matrix Pad from Spreadsheet)
### numpads and macro mads (3) missing Matrix Pad
qmk compile -c -j 0 -kb wilba_tech/rama_works_m6_a -km nug # m6a *2
qmk compile -c -j 0 -kb noxary/220 -km nug # 220 *1
### alice boards (7)
qmk compile -c -j 0 -kb mechlovin/adelais/standard_led/arm/rev4/apm32f103 -km nug # dodici *1
qmk compile -c -j 0 -kb linworks/dolice -km nug # dolice *1
qmk compile -c -j 0 -kb projectkb/alice/rev2 -km nug # nunu (black)/nunu (burg)/tengu *3
qmk compile -c -j 0 -kb xelus/valor/rev2 -km nug # nunu poly *1
qmk compile -c -j 0 -kb xelus/valor/rev1 -km nug # praxis *1
### 60% XT boards (2)
qmk compile -c -j 0 -kb aalto -km nug # aalto *1
qmk compile -c -j 0 -kb hineybush/h60_wideboi -km nug # rei *1
### 60% boards (24)
qmk compile -c -j 0 -kb hineybush/h60_al6 -km nug # al6 *1
qmk compile -c -j 0 -kb fsst60 -km nug # cw60 *1
qmk compile -c -j 0 -kb mechlovin/zed60 -km nug # derivative *1
qmk compile -c -j 0 -kb geonworks/frogmini/fms -km nug # frog mini *1
qmk compile -c -j 0 -kb kapcave/gskt00 -km nug # gskt *1
qmk compile -c -j 0 -kb mechlovin/zed60 -km nug_hex # hex.3cv2 *1
qmk compile -c -j 0 -kb idb/idb_60 -km nug # idb60 *1
qmk compile -c -j 0 -kb hineybush/h60 -km nug # kei/ogre/palmetto/ladybird/bowl60/b60 [excludes unikorn (spares)] *6
qmk compile -c -j 0 -kb jels/jels60/v1 -km nug # khajit *1
qmk compile -c -j 0 -kb buildakb/martingale -km nug # martingale *1
qmk compile -c -j 0 -kb fjlabs/midway60 -km nug # midway60 *1
qmk compile -c -j 0 -kb cannonkeys/moment -km nug # Moment *1
qmk compile -c -j 0 -kb noxary/260 -km nug # noxary x60r *1
qmk compile -c -j 0 -kb ai03/polaris -km nug # polaris *1
qmk compile -c -j 0 -kb westfoxtrot/prophet -km nug # prophet *1
qmk compile -c -j 0 -kb xelus/rs60/rev2_1 -km nug # rs60 *1
qmk compile -c -j 0 -kb daji/seis_cero -km nug # seis cero *1
qmk compile -c -j 0 -kb wilba_tech/wt60_c -km nug # tx60 *1
qmk compile -c -j 0 -kb mechlovin/jay60 -km nug # unikorn flex cut *1
### 65% boards (16)
qmk compile -c -j 0 -kb cablecardesigns/ccd65/atmel -km nug # angel *1
qmk compile -c -j 0 -kb wilba_tech/wt65_g -km nug # aurora65 *1
qmk compile -c -j 0 -kb kopibeng/mnk65_stm32 -km nug # hiro *1
qmk compile -c -j 0 -kb wilba_tech/wt65_a -km nug # kc65 red pcb *1
qmk compile -c -j 0 -kb sleepdealer/b65 -km nug # KMG B65 *1
qmk compile -c -j 0 -kb wolf/kohakusolder -km nug # kohaku alu pcb *1
qmk compile -c -j 0 -kb wolf/kohakusolderrgb -km nug # kohaku poly pcb *1
qmk compile -c -j 0 -kb noxary/x268 -km nug # lz clsms *1
qmk compile -c -j 0 -kb noxary/268_2 -km nug # noxary 268.2 brass red pcb/x65 *2
qmk compile -c -j 0 -kb noxary/268_2_rgb -km nug # noxary 268.2 white pcb (purple poly case) *1
qmk compile -c -j 0 -kb machina/orbit65 -km nug # orbit65 *1
qmk compile -c -j 0 -kb daji/seis_cinco -km nug # seis cinco *1
qmk compile -c -j 0 -kb mechlovin/hannah65/rev1 -km nug # sessantacinque *1
qmk compile -c -j 0 -kb leeku/finger65 -km nug # TX65 *1
qmk compile -c -j 0 -kb ai03/vega -km nug # vega *1
### TKL boards (21)
qmk compile -c -j 0 -kb cannonkeys/cloudline -km nug # cloudline *1
qmk compile -c -j 0 -kb hineybush/h88 -km nug # cw80/jancev2/kfe *3
qmk compile -c -j 0 -kb mechlovin/olly/orion -km nug # duck orion v2.5 *1
qmk compile -c -j 0 -kb zykrah/fuyu -km nug # f1-8k *1
qmk compile -c -j 0 -kb studiokestra/galatea/rev1 -km nug # f1-8x v2 *1
qmk compile -c -j 0 -kb hineybush/h87a -km nug # frog/salamander *2
qmk compile -c -j 0 -kb baion878/sl -km nug # Gehirn *1
qmk compile -c -j 0 -kb wilba_tech/wt80_a -km nug # kc TKL *1
qmk compile -c -j 0 -kb mechlovin/infinity875 -km nug # lz REs *1
qmk compile -c -j 0 -kb hineybush/h87a -km nug_lz_xe # lz XE *1
qmk compile -c -j 0 -kb matrix/m20add -km nug # matrix 2.0 additional *1
qmk compile -c -j 0 -kb matrix/me -km nug # matrix me *1
qmk compile -c -j 0 -kb noxary/280 -km nug # noxary 280 *2
qmk compile -c -j 0 -kb mechlovin/infinity875 -km nug_ori # ORI CLS *1
qmk compile -c -j 0 -kb hineybush/h87c_tkl_one -km nug # tkl one/kmg tkl *2
qmk compile -c -j 0 -kb hineybush/h87c_tkl_one -km nug_lime # tkl one (lime) *1
### FS boards (1)
qmk compile -c -j 0 -kb xelus/kangaroo/rev1 -km nug # kangaroo *1

#######################################
# Not used
#######################################
#qmk compile -c -j 0 -kb tgr/jane/v2ce -km nug # tgr jane v2 ce spare og pcb *1
#qmk compile -c -j 0 -kb duck/orion/v3 -km nug # duck orion v2.5 spare og pcb *1

#######################################
# Missing/Not on QMK/this repo, 2 total
#######################################
# Matrix Pad *1
# TX65 *1 (use qmk_firmware-leeku repo)

#######################################
# OLD OLD OLD OLD OLD OLD OLD OLD OLD
#######################################
#qmk compile -c -j 0 -kb dz60 -km nug_ansi # none/tofu
#qmk compile -c -j 0 -kb dz60 -km nug_tsangan # none/tofu
#qmk compile -c -j 0 -kb hineybush/physix -km nug # none/physix
#qmk compile -c -j 0 -kb singa -km nug # none/singa r2
#qmk compile -c -j 0 -kb tgr/alice -km nug # none/austere
#qmk compile -c -j 0 -kb converter/usb_usb -km nug_vita # vita *1
#qmk compile -c -j 0 -kb wilba_tech/rama_works_m65_bx -km nug # none/m65b
#qmk compile -c -j 0 -kb wilba_tech/wt60_bx -km nug # thermal *1
#qmk compile -c -j 0 -kb wilba_tech/wt60_xt -km nug # none/jubi
#qmk compile -c -j 0 -kb wilba_tech/wt65_xtx -km nug # none/zenith
#qmk compile -c -j 0 -kb wilba_tech/wt75_a -km nug # none/xeno
#qmk compile -c -j 0 -kb wilba_tech/wt75_c -km nug # none/7v
#qmk compile -c -j 0 -kb wilba_tech/zeal60 -km nug # none
#qmk compile -c -j 0 -kb xelus/dawn60 -km nug # none
#qmk compile -c -j 0 -kb converter/usb_usb -km nug_snow # f1-8k *1

# Matrix IM+ *1 (uses vial-qmk repo)
