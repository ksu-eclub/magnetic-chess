<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.5.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="Dane">
<packages>
<package name="GBJ1004-BP">
<pad name="1" x="-20" y="0" drill="1.43" shape="square"/>
<pad name="2" x="-10" y="0" drill="1.43" shape="square"/>
<pad name="3" x="-2.5" y="0" drill="1.43" shape="square"/>
<pad name="4" x="5" y="0" drill="1.43" shape="square"/>
<wire x1="-24.3" y1="-2.7" x2="-24.3" y2="2.7" width="0.127" layer="21"/>
<wire x1="-24.3" y1="2.7" x2="8.1" y2="2.7" width="0.127" layer="21"/>
<wire x1="8.1" y1="2.7" x2="8.1" y2="-2.7" width="0.127" layer="21"/>
<wire x1="8.1" y1="-2.7" x2="-24.3" y2="-2.7" width="0.127" layer="21"/>
<text x="-10.16" y="3.81" size="0.8128" layer="25">&gt;NAME</text>
</package>
<package name="SOD2512X110N" urn="urn:adsk.eagle:footprint:16707756/1" locally_modified="yes">
<description>SOD, 2.50 mm span, 1.70 X 1.25 X 1.10 mm body
&lt;p&gt;SOD package with 2.50 mm span with body size 1.70 X 1.25 X 1.10 mm&lt;/p&gt;</description>
<wire x1="0.9" y1="0.675" x2="-1.9786" y2="0.675" width="0.12" layer="21"/>
<wire x1="-1.9786" y1="0.675" x2="-1.9786" y2="-0.675" width="0.12" layer="21"/>
<wire x1="-1.9786" y1="-0.675" x2="0.9" y2="-0.675" width="0.12" layer="21"/>
<wire x1="0.9" y1="-0.675" x2="-0.9" y2="-0.675" width="0.12" layer="51"/>
<wire x1="-0.9" y1="-0.675" x2="-0.9" y2="0.675" width="0.12" layer="51"/>
<wire x1="-0.9" y1="0.675" x2="0.9" y2="0.675" width="0.12" layer="51"/>
<wire x1="0.9" y1="0.675" x2="0.9" y2="-0.675" width="0.12" layer="51"/>
<smd name="1" x="-1.2206" y="0" dx="0.888" dy="0.5718" layer="1"/>
<smd name="2" x="1.2206" y="0" dx="0.888" dy="0.5718" layer="1"/>
<text x="0" y="1.31" size="0.8128" layer="25" align="bottom-center">&gt;NAME</text>
</package>
</packages>
<packages3d>
<package3d name="SOD2512X110N" urn="urn:adsk.eagle:package:16707742/1" type="model">
<description>SOD, 2.50 mm span, 1.70 X 1.25 X 1.10 mm body
&lt;p&gt;SOD package with 2.50 mm span with body size 1.70 X 1.25 X 1.10 mm&lt;/p&gt;</description>
<packageinstances>
<packageinstance name="SOD2512X110N"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="GBJ1004-BP">
<pin name="AC_IN1" x="-30.48" y="10.16" visible="pad" length="middle"/>
<pin name="AC_IN2" x="-30.48" y="-5.08" visible="pad" length="middle"/>
<wire x1="-10.16" y1="2.54" x2="2.54" y2="15.24" width="0.254" layer="94"/>
<wire x1="2.54" y1="15.24" x2="15.24" y2="2.54" width="0.254" layer="94"/>
<wire x1="15.24" y1="2.54" x2="2.54" y2="-10.16" width="0.254" layer="94"/>
<wire x1="2.54" y1="-10.16" x2="-10.16" y2="2.54" width="0.254" layer="94"/>
<polygon width="0.254" layer="94">
<vertex x="-7.62" y="10.16"/>
<vertex x="-2.54" y="5.08"/>
<vertex x="-2.54" y="10.16"/>
</polygon>
<wire x1="-5.08" y1="12.7" x2="0" y2="7.62" width="0.254" layer="94"/>
<polygon width="0.254" layer="94">
<vertex x="5.08" y="7.62"/>
<vertex x="10.16" y="12.7"/>
<vertex x="10.16" y="7.62"/>
</polygon>
<polygon width="0.254" layer="94">
<vertex x="-7.62" y="-5.08"/>
<vertex x="-2.54" y="0"/>
<vertex x="-2.54" y="-5.08"/>
</polygon>
<polygon width="0.254" layer="94">
<vertex x="5.08" y="-2.54"/>
<vertex x="10.16" y="-7.62"/>
<vertex x="10.16" y="-2.54"/>
</polygon>
<wire x1="7.62" y1="0" x2="12.7" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-7.62" x2="0" y2="-2.54" width="0.254" layer="94"/>
<wire x1="7.62" y1="5.08" x2="12.7" y2="10.16" width="0.254" layer="94"/>
<wire x1="-25.4" y1="10.16" x2="-25.4" y2="20.32" width="0.254" layer="94"/>
<wire x1="-25.4" y1="20.32" x2="2.54" y2="20.32" width="0.254" layer="94"/>
<wire x1="2.54" y1="20.32" x2="2.54" y2="15.24" width="0.254" layer="94"/>
<wire x1="-25.4" y1="-5.08" x2="-25.4" y2="-15.24" width="0.254" layer="94"/>
<wire x1="-25.4" y1="-15.24" x2="2.54" y2="-15.24" width="0.254" layer="94"/>
<wire x1="2.54" y1="-15.24" x2="2.54" y2="-10.16" width="0.254" layer="94"/>
<wire x1="15.24" y1="2.54" x2="20.32" y2="2.54" width="0.254" layer="94"/>
<wire x1="-10.16" y1="2.54" x2="-10.16" y2="-12.7" width="0.254" layer="94"/>
<wire x1="-10.16" y1="-17.78" x2="-10.16" y2="-20.32" width="0.254" layer="94"/>
<wire x1="-10.16" y1="-20.32" x2="20.32" y2="-20.32" width="0.254" layer="94"/>
<wire x1="-10.16" y1="-12.7" x2="-10.16" y2="-17.78" width="0.254" layer="94" curve="-180"/>
<pin name="POSITIVE_DC" x="25.4" y="2.54" visible="pad" length="middle" rot="R180"/>
<pin name="NEGATIVE_DC" x="25.4" y="-20.32" visible="pad" length="middle" rot="R180"/>
<text x="-2.54" y="22.86" size="1.778" layer="95">&gt;NAME</text>
</symbol>
<symbol name="BAT54HT1G">
<pin name="ANODE(2)" x="-7.62" y="2.54" visible="pad" length="middle"/>
<pin name="CATHODE(1)" x="7.62" y="2.54" visible="pad" length="middle" rot="R180"/>
<wire x1="-2.54" y1="5.08" x2="-2.54" y2="0" width="0.254" layer="94"/>
<wire x1="-2.54" y1="0" x2="2.54" y2="2.54" width="0.254" layer="94"/>
<wire x1="2.54" y1="2.54" x2="-2.54" y2="5.08" width="0.254" layer="94"/>
<wire x1="2.54" y1="5.08" x2="2.54" y2="0" width="0.254" layer="94"/>
<text x="-5.08" y="5.08" size="1.778" layer="95">&gt;NAME</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="GBJ1004-BP" prefix="BR">
<gates>
<gate name="G$1" symbol="GBJ1004-BP" x="2.54" y="-2.54"/>
</gates>
<devices>
<device name="" package="GBJ1004-BP">
<connects>
<connect gate="G$1" pin="AC_IN1" pad="2"/>
<connect gate="G$1" pin="AC_IN2" pad="3"/>
<connect gate="G$1" pin="NEGATIVE_DC" pad="4"/>
<connect gate="G$1" pin="POSITIVE_DC" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="BAT54HT1G" prefix="D">
<gates>
<gate name="G$1" symbol="BAT54HT1G" x="0" y="-2.54"/>
</gates>
<devices>
<device name="BAT54HT1G" package="SOD2512X110N">
<connects>
<connect gate="G$1" pin="ANODE(2)" pad="2"/>
<connect gate="G$1" pin="CATHODE(1)" pad="1"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:16707742/1"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="Zach">
<packages>
<package name="ESMQ351VSN102MA50S" urn="urn:adsk.eagle:footprint:17210892/1" locally_modified="yes">
<description>Radial Polarized Capacitor, 10.00 mm pitch, 35.00 mm body diameter, 52.00 mm body height
&lt;p&gt;Radial Polarized Capacitor package with 10.00 mm pitch (lead spacing), 2.00 mm lead diameter, 35.00 mm body diameter and 52.00 mm body height&lt;/p&gt;</description>
<circle x="0" y="0" radius="18" width="0.12" layer="21"/>
<circle x="0" y="0" radius="18" width="0.12" layer="51"/>
<wire x1="-13.3249" y1="13.325" x2="-12.5749" y2="13.325" width="0.12" layer="21"/>
<wire x1="-12.9499" y1="13.7" x2="-12.9499" y2="12.95" width="0.12" layer="21"/>
<pad name="+" x="-5" y="0" drill="2.2" diameter="2.8"/>
<pad name="-" x="5" y="0" drill="2.2" diameter="2.8"/>
<text x="0" y="18.635" size="0.8128" layer="25" align="bottom-center">&gt;NAME</text>
</package>
<package name="0805">
<smd name="P$1" x="-0.9525" y="0" dx="1.2954" dy="0.7112" layer="1" rot="R90"/>
<smd name="P$2" x="0.9525" y="0" dx="1.2954" dy="0.7112" layer="1" rot="R90"/>
<text x="0" y="0.8636" size="0.254" layer="25" align="bottom-center">&gt;NAME</text>
<wire x1="-1.524" y1="0.762" x2="1.524" y2="0.762" width="0.0762" layer="21"/>
<wire x1="1.524" y1="0.762" x2="1.524" y2="-0.762" width="0.0762" layer="21"/>
<wire x1="1.524" y1="-0.762" x2="-1.524" y2="-0.762" width="0.0762" layer="21"/>
<wire x1="-1.524" y1="-0.762" x2="-1.524" y2="0.762" width="0.0762" layer="21"/>
</package>
<package name="0402" urn="urn:adsk.eagle:footprint:16053684/1" locally_modified="yes">
<description>Chip, 1.00 X 0.50 X 0.35 mm body
&lt;p&gt;Chip package with body size 1.00 X 0.50 X 0.35 mm&lt;/p&gt;</description>
<wire x1="0.5" y1="0.6199" x2="-0.5" y2="0.6199" width="0.12" layer="21"/>
<wire x1="0.5" y1="-0.6199" x2="-0.5" y2="-0.6199" width="0.12" layer="21"/>
<wire x1="0.5" y1="-0.25" x2="-0.5" y2="-0.25" width="0.12" layer="51"/>
<wire x1="-0.5" y1="-0.25" x2="-0.5" y2="0.25" width="0.12" layer="51"/>
<wire x1="-0.5" y1="0.25" x2="0.5" y2="0.25" width="0.12" layer="51"/>
<wire x1="0.5" y1="0.25" x2="0.5" y2="-0.25" width="0.12" layer="51"/>
<smd name="1" x="-0.5" y="0" dx="0.5" dy="0.6" layer="1"/>
<smd name="2" x="0.5" y="0" dx="0.5" dy="0.6" layer="1"/>
<text x="0" y="1.2549" size="0.8128" layer="25" align="bottom-center">&gt;NAME</text>
</package>
<package name="2512" urn="urn:adsk.eagle:footprint:16173500/1" locally_modified="yes">
<description>Chip, 6.30 X 3.20 X 0.60 mm body
&lt;p&gt;Chip package with body size 6.30 X 3.20 X 0.60 mm&lt;/p&gt;</description>
<wire x1="3.15" y1="1.9699" x2="-3.15" y2="1.9699" width="0.12" layer="21"/>
<wire x1="3.15" y1="-1.9699" x2="-3.15" y2="-1.9699" width="0.12" layer="21"/>
<wire x1="3.15" y1="-1.6" x2="-3.15" y2="-1.6" width="0.12" layer="51"/>
<wire x1="-3.15" y1="-1.6" x2="-3.15" y2="1.6" width="0.12" layer="51"/>
<wire x1="-3.15" y1="1.6" x2="3.15" y2="1.6" width="0.12" layer="51"/>
<wire x1="3.15" y1="1.6" x2="3.15" y2="-1.6" width="0.12" layer="51"/>
<smd name="1" x="-2.7" y="0" dx="1.6" dy="3.5" layer="1"/>
<smd name="2" x="2.7" y="0" dx="1.6" dy="3.5" layer="1"/>
<text x="0" y="2.6049" size="0.8128" layer="25" align="bottom-center">&gt;NAME</text>
</package>
<package name="ALQ3F12">
<pad name="C1" x="0" y="0" drill="1.3"/>
<pad name="C2" x="0" y="-7.62" drill="1.3"/>
<pad name="COM" x="-10.16" y="0" drill="1.3"/>
<pad name="NO" x="-17.78" y="0" drill="1.3"/>
<wire x1="3" y1="3" x2="-21" y2="3" width="0.127" layer="21"/>
<wire x1="-21" y1="3" x2="-21" y2="-11" width="0.127" layer="21"/>
<wire x1="-21" y1="-11" x2="3" y2="-11" width="0.127" layer="21"/>
<wire x1="3" y1="-11" x2="3" y2="3" width="0.127" layer="21"/>
<text x="-9" y="3" size="1.27" layer="21" align="bottom-center">&gt;NAME</text>
</package>
<package name="1-770967-0">
<description>Double-row, 4-pin Pin Header (Male) Right Angle, 4.14 mm (0.16 in) pitch, 6.10 mm mating length, 9.86 X 2.00 X 11.86 mm body
&lt;p&gt;Double-row (2X2), 4-pin Pin Header (Male) Right Angle package with 4.14 mm (0.16 in) pitch, 1.05 mm lead width, 0.76 mm tail length and 6.10 mm mating length with body size 9.86 X 2.00 X 11.86 mm, pin pattern - clockwise from top left&lt;/p&gt;</description>
<pad name="3" x="4.14" y="12.67" drill="2.07"/>
<pad name="2" x="0" y="12.67" drill="2.07"/>
<text x="0" y="15" size="1.27" layer="25" align="bottom-center">&gt;NAME</text>
<pad name="4" x="0" y="5.33" drill="3.86"/>
<wire x1="-7" y1="14.41" x2="7" y2="14.41" width="0.127" layer="21"/>
<wire x1="7" y1="14.41" x2="7" y2="0" width="0.127" layer="21"/>
<wire x1="7" y1="0" x2="-7" y2="0" width="0.127" layer="21"/>
<wire x1="-7" y1="0" x2="-7" y2="14.41" width="0.127" layer="21"/>
<pad name="1" x="-4.14" y="12.67" drill="2.07"/>
</package>
<package name="1-770969-0">
<description>Double-row, 4-pin Pin Header (Male) Right Angle, 4.14 mm (0.16 in) pitch, 6.10 mm mating length, 9.86 X 2.00 X 11.86 mm body
&lt;p&gt;Double-row (2X2), 4-pin Pin Header (Male) Right Angle package with 4.14 mm (0.16 in) pitch, 1.05 mm lead width, 0.76 mm tail length and 6.10 mm mating length with body size 9.86 X 2.00 X 11.86 mm, pin pattern - clockwise from top left&lt;/p&gt;</description>
<pad name="2" x="0" y="16.81" drill="2.07"/>
<pad name="1" x="4.14" y="16.81" drill="2.07"/>
<pad name="4" x="4.14" y="12.67" drill="2.07"/>
<pad name="5" x="0" y="12.67" drill="2.07"/>
<text x="0" y="18.7087" size="1.27" layer="25" align="bottom-center">&gt;NAME</text>
<pad name="7" x="0" y="5.33" drill="3.86"/>
<wire x1="-7" y1="18.55" x2="7" y2="18.55" width="0.127" layer="21"/>
<wire x1="7" y1="18.55" x2="7" y2="0" width="0.127" layer="21"/>
<wire x1="7" y1="0" x2="-7" y2="0" width="0.127" layer="21"/>
<wire x1="-7" y1="0" x2="-7" y2="18.55" width="0.127" layer="21"/>
<pad name="3" x="-4.14" y="16.81" drill="2.07"/>
<pad name="6" x="-4.14" y="12.67" drill="2.07"/>
</package>
</packages>
<packages3d>
<package3d name="CAPPRD1000W200D3500H5200B" urn="urn:adsk.eagle:package:17210883/1" type="model">
<description>Radial Polarized Capacitor, 10.00 mm pitch, 35.00 mm body diameter, 52.00 mm body height
&lt;p&gt;Radial Polarized Capacitor package with 10.00 mm pitch (lead spacing), 2.00 mm lead diameter, 35.00 mm body diameter and 52.00 mm body height&lt;/p&gt;</description>
<packageinstances>
<packageinstance name="ESMQ351VSN102MA50S"/>
</packageinstances>
</package3d>
<package3d name="RESC6332X60N" urn="urn:adsk.eagle:package:16173394/1" type="model">
<description>Chip, 6.30 X 3.20 X 0.60 mm body
&lt;p&gt;Chip package with body size 6.30 X 3.20 X 0.60 mm&lt;/p&gt;</description>
<packageinstances>
<packageinstance name="2512"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="ESMQ351VSN102MA50S">
<wire x1="0" y1="2.54" x2="0" y2="-2.54" width="0.254" layer="94"/>
<wire x1="2.54" y1="-2.54" x2="2.54" y2="2.54" width="0.254" layer="94" curve="-67.380135"/>
<pin name="+" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
<pin name="-" x="5.08" y="0" visible="off" length="short" direction="pas" rot="R180"/>
<wire x1="1.778" y1="0" x2="2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="3.81" x2="-2.54" y2="1.27" width="0.254" layer="94"/>
<wire x1="-3.81" y1="2.54" x2="-1.27" y2="2.54" width="0.254" layer="94"/>
<text x="-2.54" y="5.08" size="1.27" layer="95">&gt;NAME</text>
<text x="-2.54" y="-5.08" size="1.27" layer="96">&gt;VALUE</text>
</symbol>
<symbol name="RESISTOR">
<pin name="P$1" x="0" y="0" visible="off" length="short" direction="pas"/>
<pin name="P$2" x="15.24" y="0" visible="off" length="short" direction="pas" rot="R180"/>
<wire x1="2.54" y1="0" x2="3.386665625" y2="2.54" width="0.1524" layer="94"/>
<wire x1="3.386665625" y1="2.54" x2="5.08" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="5.08" y1="-2.54" x2="6.773334375" y2="2.54" width="0.1524" layer="94"/>
<wire x1="6.773334375" y1="2.54" x2="8.4666625" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="8.466665625" y1="-2.54" x2="10.16" y2="2.54" width="0.1524" layer="94"/>
<wire x1="10.16" y1="2.54" x2="11.853334375" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="11.853334375" y1="-2.54" x2="12.7" y2="0" width="0.1524" layer="94"/>
<text x="7.62" y="2.54" size="1.778" layer="95" align="bottom-center">&gt;NAME</text>
<text x="7.62" y="-5.08" size="1.778" layer="96" align="bottom-center">&gt;VALUE</text>
</symbol>
<symbol name="GND">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
<wire x1="-0.635" y1="-1.27" x2="0.635" y2="-1.27" width="0.254" layer="94"/>
</symbol>
<symbol name="ALQ3F12">
<pin name="S1" x="0" y="0" visible="pad" length="middle"/>
<pin name="S2" x="17.78" y="0" visible="pad" length="middle" rot="R180"/>
<pin name="C1" x="0" y="5.08" visible="pad" length="middle"/>
<pin name="C2" x="17.78" y="5.08" visible="pad" length="middle" rot="R180"/>
<wire x1="5.08" y1="-2.54" x2="12.7" y2="-2.54" width="0.254" layer="94"/>
<wire x1="12.7" y1="-2.54" x2="12.7" y2="5.08" width="0.254" layer="94"/>
<wire x1="12.7" y1="5.08" x2="12.7" y2="7.62" width="0.254" layer="94"/>
<wire x1="12.7" y1="7.62" x2="5.08" y2="7.62" width="0.254" layer="94"/>
<wire x1="5.08" y1="7.62" x2="5.08" y2="5.08" width="0.254" layer="94"/>
<text x="7.62" y="7.62" size="0.8128" layer="95">&gt;NAME</text>
<wire x1="5.08" y1="5.08" x2="5.08" y2="0" width="0.254" layer="94"/>
<wire x1="5.08" y1="0" x2="5.08" y2="-2.54" width="0.254" layer="94"/>
<wire x1="5.08" y1="5.08" x2="7.62" y2="5.08" width="0.254" layer="94" curve="-180"/>
<wire x1="7.62" y1="5.08" x2="10.16" y2="5.08" width="0.254" layer="94" curve="-180"/>
<wire x1="10.16" y1="5.08" x2="12.7" y2="5.08" width="0.254" layer="94" curve="-180"/>
<wire x1="5.08" y1="0" x2="12.065" y2="1.27" width="0.254" layer="94"/>
</symbol>
<symbol name="1-770967-0">
<pin name="GND" x="0" y="2.54" length="middle" direction="pas"/>
<pin name="ON" x="0" y="5.08" length="middle" direction="out"/>
<pin name="DETECT" x="0" y="7.62" length="middle" direction="pwr"/>
<wire x1="5.08" y1="0" x2="5.08" y2="10.16" width="0.254" layer="94"/>
<wire x1="5.08" y1="10.16" x2="17.78" y2="10.16" width="0.254" layer="94"/>
<wire x1="17.78" y1="10.16" x2="17.78" y2="0" width="0.254" layer="94"/>
<wire x1="17.78" y1="0" x2="5.08" y2="0" width="0.254" layer="94"/>
<text x="7.62" y="10.16" size="1.27" layer="95">&gt;NAME</text>
</symbol>
<symbol name="CAPACITOR">
<pin name="P$1" x="0" y="0" visible="off" length="short" direction="pas"/>
<pin name="P$2" x="7.62" y="0" visible="off" length="short" direction="pas" rot="R180"/>
<wire x1="3.175" y1="2.54" x2="3.175" y2="0" width="0.1524" layer="94"/>
<wire x1="3.175" y1="0" x2="3.175" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="4.445" y1="2.54" x2="4.445" y2="0" width="0.1524" layer="94"/>
<text x="3.81" y="2.54" size="1.778" layer="95" align="bottom-center">&gt;NAME</text>
<text x="3.81" y="-5.08" size="1.778" layer="96" align="bottom-center">&gt;VALUE</text>
<wire x1="4.445" y1="0" x2="4.445" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="2.54" y1="0" x2="3.175" y2="0" width="0.1524" layer="94"/>
<wire x1="4.445" y1="0" x2="5.08" y2="0" width="0.1524" layer="94"/>
</symbol>
<symbol name="+170V">
<wire x1="-1.27" y1="0" x2="1.27" y2="0" width="0.254" layer="94"/>
<text x="0" y="2.54" size="1.778" layer="96" rot="R180" align="bottom-center">&gt;VALUE</text>
<pin name="+170V" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
<symbol name="1-770969-0">
<pin name="+3V3" x="0" y="2.54" length="middle" direction="pwr"/>
<pin name="+5V" x="0" y="5.08" length="middle" direction="pwr"/>
<pin name="+12V" x="0" y="7.62" length="middle" direction="pwr"/>
<pin name="+170V" x="27.94" y="7.62" length="middle" direction="pwr" rot="R180"/>
<pin name="GND" x="27.94" y="2.54" length="middle" direction="pas" rot="R180"/>
<wire x1="5.08" y1="0" x2="5.08" y2="10.16" width="0.254" layer="94"/>
<wire x1="5.08" y1="10.16" x2="22.86" y2="10.16" width="0.254" layer="94"/>
<wire x1="22.86" y1="10.16" x2="22.86" y2="0" width="0.254" layer="94"/>
<wire x1="22.86" y1="0" x2="5.08" y2="0" width="0.254" layer="94"/>
<text x="10.16" y="10.16" size="1.27" layer="95">&gt;NAME</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="ESMQ351VSN102MA50S" prefix="C" uservalue="yes">
<gates>
<gate name="G$1" symbol="ESMQ351VSN102MA50S" x="0" y="0"/>
</gates>
<devices>
<device name="" package="ESMQ351VSN102MA50S">
<connects>
<connect gate="G$1" pin="+" pad="+"/>
<connect gate="G$1" pin="-" pad="-"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:17210883/1"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="RESISTOR" prefix="R" uservalue="yes">
<gates>
<gate name="G$1" symbol="RESISTOR" x="0" y="0"/>
</gates>
<devices>
<device name="0805" package="0805">
<connects>
<connect gate="G$1" pin="P$1" pad="P$1"/>
<connect gate="G$1" pin="P$2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="0402" package="0402">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="2512" package="2512">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$2" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:16173394/1"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="GND" prefix="GND">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ALQ3F12" prefix="K">
<gates>
<gate name="G$1" symbol="ALQ3F12" x="-7.62" y="-2.54"/>
</gates>
<devices>
<device name="" package="ALQ3F12">
<connects>
<connect gate="G$1" pin="C1" pad="C1"/>
<connect gate="G$1" pin="C2" pad="C2"/>
<connect gate="G$1" pin="S1" pad="COM"/>
<connect gate="G$1" pin="S2" pad="NO"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="1-770967-0" prefix="J">
<gates>
<gate name="G$1" symbol="1-770967-0" x="-7.62" y="-5.08"/>
</gates>
<devices>
<device name="" package="1-770967-0">
<connects>
<connect gate="G$1" pin="DETECT" pad="1"/>
<connect gate="G$1" pin="GND" pad="3"/>
<connect gate="G$1" pin="ON" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="CAPACITOR" prefix="C" uservalue="yes">
<gates>
<gate name="G$1" symbol="CAPACITOR" x="0" y="0"/>
</gates>
<devices>
<device name="0805" package="0805">
<connects>
<connect gate="G$1" pin="P$1" pad="P$1"/>
<connect gate="G$1" pin="P$2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="0402" package="0402">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="+170V" prefix="P+">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="+170V" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="1-770969-0" prefix="J">
<gates>
<gate name="G$1" symbol="1-770969-0" x="-12.7" y="-5.08"/>
</gates>
<devices>
<device name="" package="1-770969-0">
<connects>
<connect gate="G$1" pin="+12V" pad="3"/>
<connect gate="G$1" pin="+170V" pad="5"/>
<connect gate="G$1" pin="+3V3" pad="1"/>
<connect gate="G$1" pin="+5V" pad="2"/>
<connect gate="G$1" pin="GND" pad="4 6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="Jim">
<packages>
<package name="703W-00/04">
<polygon width="0" layer="46">
<vertex x="1" y="-3.5" curve="-180"/>
<vertex x="-1" y="-3.5"/>
<vertex x="-1" y="3.5" curve="-180"/>
<vertex x="1" y="3.5"/>
</polygon>
<polygon width="0" layer="1">
<vertex x="3" y="-3.5" curve="-180"/>
<vertex x="-3" y="-3.5"/>
<vertex x="-3" y="3.5" curve="-180"/>
<vertex x="3" y="3.5"/>
</polygon>
<polygon width="0" layer="46">
<vertex x="15" y="-3.5" curve="-180"/>
<vertex x="13" y="-3.5"/>
<vertex x="13" y="3.5" curve="-180"/>
<vertex x="15" y="3.5"/>
</polygon>
<polygon width="0" layer="1">
<vertex x="17" y="-3.5" curve="-180"/>
<vertex x="11" y="-3.5"/>
<vertex x="11" y="3.5" curve="-180"/>
<vertex x="17" y="3.5"/>
</polygon>
<polygon width="0" layer="46">
<vertex x="8" y="0.5" curve="-180"/>
<vertex x="6" y="0.5"/>
<vertex x="6" y="7.5" curve="-180"/>
<vertex x="8" y="7.5"/>
</polygon>
<polygon width="0" layer="1">
<vertex x="10" y="0.5" curve="-180"/>
<vertex x="4" y="0.5"/>
<vertex x="4" y="7.5" curve="-180"/>
<vertex x="10" y="7.5"/>
</polygon>
<polygon width="0" layer="16">
<vertex x="3" y="-3.5" curve="-180"/>
<vertex x="-3" y="-3.5"/>
<vertex x="-3" y="3.5" curve="-180"/>
<vertex x="3" y="3.5"/>
</polygon>
<polygon width="0" layer="16">
<vertex x="17" y="-3.5" curve="-180"/>
<vertex x="11" y="-3.5"/>
<vertex x="11" y="3.5" curve="-180"/>
<vertex x="17" y="3.5"/>
</polygon>
<wire x1="-3.81" y1="-8.89" x2="17.78" y2="-8.89" width="0.127" layer="21"/>
<wire x1="17.78" y1="-8.89" x2="19.05" y2="-7.62" width="0.127" layer="21"/>
<wire x1="19.05" y1="-7.62" x2="19.05" y2="6.35" width="0.127" layer="21"/>
<wire x1="19.05" y1="6.35" x2="13.97" y2="11.43" width="0.127" layer="21"/>
<wire x1="13.97" y1="11.43" x2="0" y2="11.43" width="0.127" layer="21"/>
<wire x1="0" y1="11.43" x2="-5.08" y2="6.35" width="0.127" layer="21"/>
<wire x1="-5.08" y1="6.35" x2="-5.08" y2="-7.62" width="0.127" layer="21"/>
<wire x1="-5.08" y1="-7.62" x2="-3.81" y2="-8.89" width="0.127" layer="21"/>
<text x="3.81" y="-11.43" size="0.8128" layer="21">&gt;NAME</text>
<text x="12.7" y="-3.81" size="1.27" layer="21">Live</text>
<text x="5.08" y="1.27" size="1.27" layer="21">Ground</text>
<pad name="N" x="0" y="0" drill="0.6" shape="square"/>
<pad name="L" x="13.97" y="0" drill="0.6" shape="square"/>
<pad name="G" x="6.985" y="4.445" drill="0.6" shape="square"/>
<wire x1="-1" y1="3.5" x2="-1" y2="-3.5" width="0.127" layer="29"/>
<wire x1="-1" y1="-3.5" x2="1" y2="-3.5" width="0.127" layer="29" curve="180"/>
<wire x1="1" y1="-3.5" x2="1" y2="3.5" width="0.127" layer="29"/>
<wire x1="1" y1="3.5" x2="-1" y2="3.5" width="0.127" layer="29" curve="180"/>
<polygon width="0.127" layer="29">
<vertex x="-3" y="3.5"/>
<vertex x="-3" y="-3.5" curve="180"/>
<vertex x="3" y="-3.5"/>
<vertex x="3" y="3.5" curve="180"/>
</polygon>
<polygon width="0" layer="16">
<vertex x="10" y="0.5" curve="-180"/>
<vertex x="4" y="0.5"/>
<vertex x="4" y="7.5" curve="-180"/>
<vertex x="10" y="7.5"/>
</polygon>
<polygon width="0.127" layer="29">
<vertex x="4" y="7.5"/>
<vertex x="4" y="0.5" curve="180"/>
<vertex x="10" y="0.5"/>
<vertex x="10" y="7.5" curve="180"/>
</polygon>
<polygon width="0.127" layer="29">
<vertex x="11" y="3.5"/>
<vertex x="11" y="-3.5" curve="180"/>
<vertex x="17" y="-3.5"/>
<vertex x="17" y="3.5" curve="180"/>
</polygon>
<wire x1="-3" y1="4" x2="-3" y2="3.5" width="0.127" layer="30"/>
<wire x1="3" y1="3.5" x2="3" y2="4" width="0.127" layer="30"/>
<polygon width="0.127" layer="30">
<vertex x="3" y="-4" curve="-161.075356"/>
<vertex x="-3" y="-4"/>
<vertex x="-3" y="3.5" curve="-180"/>
<vertex x="3" y="3.5"/>
</polygon>
<polygon width="0.127" layer="30">
<vertex x="10" y="0" curve="-161.075356"/>
<vertex x="4" y="0"/>
<vertex x="4" y="7.5" curve="-180"/>
<vertex x="10" y="7.5"/>
</polygon>
<polygon width="0.127" layer="30">
<vertex x="17" y="-4" curve="-161.075356"/>
<vertex x="11" y="-4"/>
<vertex x="11" y="3.5" curve="-180"/>
<vertex x="17" y="3.5"/>
</polygon>
</package>
</packages>
<symbols>
<symbol name="703W-00/04">
<pin name="LIVE" x="0" y="12.7" visible="pad" length="middle" rot="R270"/>
<pin name="EARTH" x="12.7" y="0" visible="pad" length="middle" rot="R180"/>
<pin name="NEUTRAL" x="0" y="-12.7" visible="pad" length="middle" rot="R90"/>
<circle x="0" y="0" radius="8.032184375" width="0.254" layer="94"/>
<wire x1="-5.08" y1="0" x2="0" y2="0" width="0.254" layer="94" curve="-180"/>
<wire x1="0" y1="0" x2="5.08" y2="0" width="0.254" layer="94" curve="180"/>
<text x="-12.7" y="10.16" size="1.778" layer="95">&gt;NAME</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="703W-00/04" prefix="P">
<gates>
<gate name="G$1" symbol="703W-00/04" x="0" y="0"/>
</gates>
<devices>
<device name="" package="703W-00/04">
<connects>
<connect gate="G$1" pin="EARTH" pad="G"/>
<connect gate="G$1" pin="LIVE" pad="L"/>
<connect gate="G$1" pin="NEUTRAL" pad="N"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="BR1" library="Dane" deviceset="GBJ1004-BP" device=""/>
<part name="C1" library="Zach" deviceset="ESMQ351VSN102MA50S" device="" package3d_urn="urn:adsk.eagle:package:17210883/1" value="1000 uF"/>
<part name="C2" library="Zach" deviceset="ESMQ351VSN102MA50S" device="" package3d_urn="urn:adsk.eagle:package:17210883/1" value="1000 uF"/>
<part name="R1" library="Zach" deviceset="RESISTOR" device="0805" value="0R"/>
<part name="R2" library="Zach" deviceset="RESISTOR" device="0805" value="0R"/>
<part name="R3" library="Zach" deviceset="RESISTOR" device="0805" value="0R"/>
<part name="GND1" library="Zach" deviceset="GND" device=""/>
<part name="R4" library="Zach" deviceset="RESISTOR" device="0805" value="2.7M"/>
<part name="P1" library="Jim" deviceset="703W-00/04" device=""/>
<part name="GND2" library="Zach" deviceset="GND" device=""/>
<part name="K1" library="Zach" deviceset="ALQ3F12" device=""/>
<part name="D1" library="Dane" deviceset="BAT54HT1G" device="BAT54HT1G" package3d_urn="urn:adsk.eagle:package:16707742/1"/>
<part name="GND3" library="Zach" deviceset="GND" device=""/>
<part name="J1" library="Zach" deviceset="1-770967-0" device=""/>
<part name="C3" library="Zach" deviceset="CAPACITOR" device="0805" value="0.1 uF"/>
<part name="GND4" library="Zach" deviceset="GND" device=""/>
<part name="GND5" library="Zach" deviceset="GND" device=""/>
<part name="P+1" library="Zach" deviceset="+170V" device=""/>
<part name="J2" library="Zach" deviceset="1-770969-0" device=""/>
<part name="P+2" library="Zach" deviceset="+170V" device=""/>
<part name="GND6" library="Zach" deviceset="GND" device=""/>
</parts>
<sheets>
<sheet>
<plain>
<text x="-83.82" y="10.16" size="1.778" layer="91">For 170V output, don't populate R2 or C2.
For 340V output, don't populate R1 or R3.</text>
</plain>
<instances>
<instance part="BR1" gate="G$1" x="-20.32" y="55.88" smashed="yes">
<attribute name="NAME" x="-22.86" y="78.74" size="1.778" layer="95"/>
</instance>
<instance part="C1" gate="G$1" x="17.78" y="30.48" smashed="yes" rot="R270">
<attribute name="NAME" x="22.86" y="33.02" size="1.27" layer="95" rot="R270"/>
<attribute name="VALUE" x="12.7" y="33.02" size="1.27" layer="96" rot="R270"/>
</instance>
<instance part="C2" gate="G$1" x="17.78" y="7.62" smashed="yes" rot="R270">
<attribute name="NAME" x="22.86" y="10.16" size="1.27" layer="95" rot="R270"/>
<attribute name="VALUE" x="12.7" y="10.16" size="1.27" layer="96" rot="R270"/>
</instance>
<instance part="R1" gate="G$1" x="-66.04" y="50.8" smashed="yes">
<attribute name="NAME" x="-58.42" y="53.34" size="1.778" layer="95" align="bottom-center"/>
<attribute name="VALUE" x="-58.42" y="45.72" size="1.778" layer="96" align="bottom-center"/>
</instance>
<instance part="R2" gate="G$1" x="-68.58" y="27.94" smashed="yes" rot="R90">
<attribute name="NAME" x="-71.12" y="35.56" size="1.778" layer="95" rot="R90" align="bottom-center"/>
<attribute name="VALUE" x="-63.5" y="35.56" size="1.778" layer="96" rot="R90" align="bottom-center"/>
</instance>
<instance part="R3" gate="G$1" x="0" y="-2.54" smashed="yes" rot="R90">
<attribute name="NAME" x="-2.54" y="5.08" size="1.778" layer="95" rot="R90" align="bottom-center"/>
<attribute name="VALUE" x="5.08" y="5.08" size="1.778" layer="96" rot="R90" align="bottom-center"/>
</instance>
<instance part="GND1" gate="1" x="33.02" y="-10.16" smashed="yes"/>
<instance part="R4" gate="G$1" x="33.02" y="10.16" smashed="yes" rot="R90">
<attribute name="NAME" x="30.48" y="17.78" size="1.778" layer="95" rot="R90" align="bottom-center"/>
<attribute name="VALUE" x="38.1" y="17.78" size="1.778" layer="96" rot="R90" align="bottom-center"/>
</instance>
<instance part="P1" gate="G$1" x="-81.28" y="60.96" smashed="yes">
<attribute name="NAME" x="-93.98" y="71.12" size="1.778" layer="95"/>
</instance>
<instance part="GND2" gate="1" x="5.08" y="33.02" smashed="yes"/>
<instance part="K1" gate="G$1" x="-73.66" y="76.2" smashed="yes">
<attribute name="NAME" x="-66.04" y="83.82" size="0.8128" layer="95"/>
</instance>
<instance part="D1" gate="G$1" x="-66.04" y="88.9" smashed="yes">
<attribute name="NAME" x="-71.12" y="93.98" size="1.778" layer="95"/>
</instance>
<instance part="GND3" gate="1" x="-83.82" y="86.36" smashed="yes"/>
<instance part="J1" gate="G$1" x="-30.48" y="88.9" smashed="yes">
<attribute name="NAME" x="-22.86" y="99.06" size="1.27" layer="95"/>
</instance>
<instance part="C3" gate="G$1" x="-43.18" y="88.9" smashed="yes" rot="R90">
<attribute name="NAME" x="-45.72" y="92.71" size="1.778" layer="95" rot="R90" align="bottom-center"/>
<attribute name="VALUE" x="-38.1" y="92.71" size="1.778" layer="96" rot="R90" align="bottom-center"/>
</instance>
<instance part="GND4" gate="1" x="-43.18" y="86.36" smashed="yes"/>
<instance part="GND5" gate="1" x="-33.02" y="88.9" smashed="yes"/>
<instance part="P+1" gate="G$1" x="38.1" y="48.26" smashed="yes">
<attribute name="VALUE" x="38.1" y="50.8" size="1.778" layer="96" rot="R180" align="bottom-center"/>
</instance>
<instance part="J2" gate="G$1" x="10.16" y="73.66" smashed="yes">
<attribute name="NAME" x="20.32" y="83.82" size="1.27" layer="95"/>
</instance>
<instance part="P+2" gate="G$1" x="38.1" y="83.82" smashed="yes">
<attribute name="VALUE" x="38.1" y="86.36" size="1.778" layer="96" rot="R180" align="bottom-center"/>
</instance>
<instance part="GND6" gate="1" x="38.1" y="73.66" smashed="yes"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="BR1" gate="G$1" pin="AC_IN2"/>
<pinref part="R1" gate="G$1" pin="P$2"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="R2" gate="G$1" pin="P$2"/>
<wire x1="-68.58" y1="43.18" x2="-68.58" y2="48.26" width="0.1524" layer="91"/>
<pinref part="R1" gate="G$1" pin="P$1"/>
<wire x1="-68.58" y1="48.26" x2="-68.58" y2="50.8" width="0.1524" layer="91"/>
<wire x1="-68.58" y1="50.8" x2="-66.04" y2="50.8" width="0.1524" layer="91"/>
<pinref part="P1" gate="G$1" pin="NEUTRAL"/>
<wire x1="-81.28" y1="48.26" x2="-68.58" y2="48.26" width="0.1524" layer="91"/>
<junction x="-68.58" y="48.26"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="C2" gate="G$1" pin="+"/>
<wire x1="0" y1="25.4" x2="17.78" y2="25.4" width="0.1524" layer="91"/>
<wire x1="17.78" y1="25.4" x2="17.78" y2="10.16" width="0.1524" layer="91"/>
<pinref part="C1" gate="G$1" pin="-"/>
<junction x="17.78" y="25.4"/>
<pinref part="R2" gate="G$1" pin="P$1"/>
<wire x1="-68.58" y1="27.94" x2="-68.58" y2="25.4" width="0.1524" layer="91"/>
<pinref part="R3" gate="G$1" pin="P$2"/>
<wire x1="-68.58" y1="25.4" x2="0" y2="25.4" width="0.1524" layer="91"/>
<wire x1="0" y1="25.4" x2="0" y2="12.7" width="0.1524" layer="91"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="C2" gate="G$1" pin="-"/>
<wire x1="0" y1="-2.54" x2="17.78" y2="-2.54" width="0.1524" layer="91"/>
<wire x1="17.78" y1="-2.54" x2="17.78" y2="2.54" width="0.1524" layer="91"/>
<pinref part="R3" gate="G$1" pin="P$1"/>
<wire x1="17.78" y1="-2.54" x2="33.02" y2="-2.54" width="0.1524" layer="91"/>
<junction x="17.78" y="-2.54"/>
<pinref part="GND1" gate="1" pin="GND"/>
<wire x1="33.02" y1="-2.54" x2="33.02" y2="-7.62" width="0.1524" layer="91"/>
<pinref part="R4" gate="G$1" pin="P$1"/>
<wire x1="33.02" y1="10.16" x2="33.02" y2="-2.54" width="0.1524" layer="91"/>
<junction x="33.02" y="-2.54"/>
</segment>
<segment>
<pinref part="BR1" gate="G$1" pin="NEGATIVE_DC"/>
<pinref part="GND2" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="GND3" gate="1" pin="GND"/>
<wire x1="-83.82" y1="88.9" x2="-83.82" y2="91.44" width="0.1524" layer="91"/>
<pinref part="K1" gate="G$1" pin="C1"/>
<wire x1="-73.66" y1="81.28" x2="-76.2" y2="81.28" width="0.1524" layer="91"/>
<wire x1="-76.2" y1="81.28" x2="-76.2" y2="91.44" width="0.1524" layer="91"/>
<pinref part="D1" gate="G$1" pin="ANODE(2)"/>
<wire x1="-76.2" y1="91.44" x2="-73.66" y2="91.44" width="0.1524" layer="91"/>
<wire x1="-83.82" y1="91.44" x2="-73.66" y2="91.44" width="0.1524" layer="91"/>
<junction x="-73.66" y="91.44"/>
</segment>
<segment>
<pinref part="C3" gate="G$1" pin="P$1"/>
<pinref part="GND4" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="J1" gate="G$1" pin="GND"/>
<wire x1="-30.48" y1="91.44" x2="-33.02" y2="91.44" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$1" pin="ON"/>
<wire x1="-33.02" y1="91.44" x2="-33.02" y2="93.98" width="0.1524" layer="91"/>
<wire x1="-33.02" y1="93.98" x2="-30.48" y2="93.98" width="0.1524" layer="91"/>
<pinref part="GND5" gate="1" pin="GND"/>
<junction x="-33.02" y="91.44"/>
</segment>
<segment>
<pinref part="J2" gate="G$1" pin="GND"/>
<pinref part="GND6" gate="1" pin="GND"/>
</segment>
</net>
<net name="+170V" class="0">
<segment>
<pinref part="C1" gate="G$1" pin="+"/>
<pinref part="BR1" gate="G$1" pin="POSITIVE_DC"/>
<wire x1="17.78" y1="33.02" x2="17.78" y2="45.72" width="0.1524" layer="91"/>
<wire x1="17.78" y1="45.72" x2="5.08" y2="58.42" width="0.1524" layer="91"/>
<wire x1="17.78" y1="45.72" x2="33.02" y2="45.72" width="0.1524" layer="91"/>
<junction x="17.78" y="45.72"/>
<pinref part="R4" gate="G$1" pin="P$2"/>
<wire x1="33.02" y1="45.72" x2="38.1" y2="45.72" width="0.1524" layer="91"/>
<wire x1="33.02" y1="25.4" x2="33.02" y2="45.72" width="0.1524" layer="91"/>
<junction x="33.02" y="45.72"/>
<pinref part="P+1" gate="G$1" pin="+170V"/>
</segment>
<segment>
<pinref part="J2" gate="G$1" pin="+170V"/>
<pinref part="P+2" gate="G$1" pin="+170V"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="P1" gate="G$1" pin="LIVE"/>
<wire x1="-81.28" y1="73.66" x2="-81.28" y2="76.2" width="0.1524" layer="91"/>
<pinref part="K1" gate="G$1" pin="S1"/>
<wire x1="-81.28" y1="76.2" x2="-73.66" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="K1" gate="G$1" pin="S2"/>
<pinref part="BR1" gate="G$1" pin="AC_IN1"/>
<wire x1="-55.88" y1="76.2" x2="-50.8" y2="76.2" width="0.1524" layer="91"/>
<wire x1="-50.8" y1="76.2" x2="-50.8" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="K1" gate="G$1" pin="C2"/>
<wire x1="-55.88" y1="81.28" x2="-53.34" y2="81.28" width="0.1524" layer="91"/>
<pinref part="D1" gate="G$1" pin="CATHODE(1)"/>
<wire x1="-53.34" y1="81.28" x2="-53.34" y2="91.44" width="0.1524" layer="91"/>
<wire x1="-53.34" y1="91.44" x2="-58.42" y2="91.44" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$1" pin="DETECT"/>
<wire x1="-30.48" y1="96.52" x2="-43.18" y2="96.52" width="0.1524" layer="91"/>
<wire x1="-43.18" y1="96.52" x2="-53.34" y2="96.52" width="0.1524" layer="91"/>
<wire x1="-53.34" y1="96.52" x2="-53.34" y2="91.44" width="0.1524" layer="91"/>
<junction x="-53.34" y="91.44"/>
<pinref part="C3" gate="G$1" pin="P$2"/>
<junction x="-43.18" y="96.52"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="6.3" minversion="6.2.2" severity="warning">
Since Version 6.2.2 text objects can contain more than one line,
which will not be processed correctly with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
