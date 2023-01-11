#!/bin/bash

# 34 lines, 42 total keyboards
qmk compile -kb wilba_tech/rama_works_m6_a -km nug # m6a *2
qmk compile -kb noxary/220 -km nug # 220 *1
qmk compile -kb xelus/valor/rev2 -km nug # nunu *1
qmk compile -kb xelus/valor/rev1 -km nug # praxis *1
qmk compile -kb projectkb/alice/rev2 -km nug # tengu *1
qmk compile -kb hineybush/h60_wideboi -km nug # rei *1
qmk compile -kb cannonkeys/moment -km nug # Moment *1
qmk compile -kb fjlabs/midway60 -km nug # midway60 *1
qmk compile -kb geonworks/frogmini/fms -km nug # frog mini *1
qmk compile -kb kapcave/gskt00 -km nug # gskt *1
qmk compile -kb idb/idb_60 -km nug # idb60 *1
qmk compile -kb hineybush/h60 -km nug # kei/ogre/palmetto *3 [unikorn (spares)]
qmk compile -kb mechlovin/jay60 -km nug # unikorn flex cut *1
qmk compile -kb noxary/260 -km nug # x60r *1
qmk compile -kb ai03/polaris -km nug # polaris *1
qmk compile -kb westfoxtrot/prophet -km nug # prophet *1
qmk compile -kb wilba_tech/wt60_c -km nug # tx60 *1
qmk compile -kb wilba_tech/wt65_g -km nug # graphite/aurora65  *1
qmk compile -kb wilba_tech/wt65_a -km nug # kc65 red pcb *1
qmk compile -kb noxary/x268 -km nug # lz clsms *1
qmk compile -kb noxary/268_2 -km nug # 268.2 red/x65 *2
qmk compile -kb noxary/268_2_rgb -km nug # 268.2 white pcb (purple case) *1
qmk compile -kb mechlovin/hannah65/rev1 -km nug # sessantacinque *1
qmk compile -kb ai03/vega -km nug # vega *1
qmk compile -kb cannonkeys/cloudline -km nug # cloudline *1
qmk compile -kb zykrah/fuyu -km nug # f1-8k *1
qmk compile -kb hineybush/h87a -km nug # frog/salamander/tkl_one *3
qmk compile -kb hineybush/h87a -km nug_lz_xe # lz XE *1
qmk compile -kb hineybush/h88 -km nug # jance/kfe ce *2
qmk compile -kb mechlovin/infinity875 -km nug # lz REs *1
qmk compile -kb matrix/m20add -km nug # 2.0 additional *1
qmk compile -kb matrix/me -km nug # matrix me *1
qmk compile -kb noxary/280 -km nug # 280 *2
qmk compile -kb xelus/kangaroo/rev1 -km nug # roo *1

#######################################
# Missing/Not on QMK/this repo, 3 total
#######################################
# Matrix Pad *2
# TX65 *1 (use qmk_firmware-leeku repo)

#######################################
# OLD OLD OLD OLD OLD OLD OLD OLD OLD
#######################################
#qmk compile -kb dz60 -km nug_ansi # none/tofu
#qmk compile -kb dz60 -km nug_tsangan # none/tofu
#qmk compile -kb hineybush/physix -km nug # none/physix
#qmk compile -kb singa -km nug # none/singa r2
#qmk compile -kb tgr/alice -km nug # none/austere
#qmk compile -kb converter/usb_usb -km nug_vita # vita *1
#qmk compile -kb wilba_tech/rama_works_m65_bx -km nug # none/m65b
#qmk compile -kb wilba_tech/wt60_bx -km nug # thermal *1
#qmk compile -kb wilba_tech/wt60_xt -km nug # none/jubi
#qmk compile -kb wilba_tech/wt65_xtx -km nug # none/zenith
#qmk compile -kb wilba_tech/wt75_a -km nug # none/xeno
#qmk compile -kb wilba_tech/wt75_c -km nug # none/7v
#qmk compile -kb wilba_tech/zeal60 -km nug # none
#qmk compile -kb xelus/dawn60 -km nug # none
#qmk compile -kb converter/usb_usb -km nug_snow # f1-8k *1

# Matrix IM+ *1 (uses vial-qmk repo)
