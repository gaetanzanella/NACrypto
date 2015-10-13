/*
Code automatically generated by KeccakTools!

The Keccak sponge function, designed by Guido Bertoni, Joan Daemen,
Michaël Peeters and Gilles Van Assche. For more information, feedback or
questions, please refer to our website: http://keccak.noekeon.org/

Implementation by the designers,
hereby denoted as "the implementer".

To the extent possible under law, the implementer has waived all copyright
and related or neighboring rights to the source code in this file.
http://creativecommons.org/publicdomain/zero/1.0/
*/

#ifndef _Keccak1600_32_s2_h_
#define _Keccak1600_32_s2_h_

#define declareABCDE \
    UINT32 Aba0, Abe0, Abi0, Abo0, Abu0; \
    UINT32 Aba1, Abe1, Abi1, Abo1, Abu1; \
    UINT32 Aga0, Age0, Agi0, Ago0, Agu0; \
    UINT32 Aga1, Age1, Agi1, Ago1, Agu1; \
    UINT32 Aka0, Ake0, Aki0, Ako0, Aku0; \
    UINT32 Aka1, Ake1, Aki1, Ako1, Aku1; \
    UINT32 Ama0, Ame0, Ami0, Amo0, Amu0; \
    UINT32 Ama1, Ame1, Ami1, Amo1, Amu1; \
    UINT32 Asa0, Ase0, Asi0, Aso0, Asu0; \
    UINT32 Asa1, Ase1, Asi1, Aso1, Asu1; \
    UINT32 Bba0, Bbe0, Bbi0, Bbo0, Bbu0; \
    UINT32 Bba1, Bbe1, Bbi1, Bbo1, Bbu1; \
    UINT32 Bga0, Bge0, Bgi0, Bgo0, Bgu0; \
    UINT32 Bga1, Bge1, Bgi1, Bgo1, Bgu1; \
    UINT32 Bka0, Bke0, Bki0, Bko0, Bku0; \
    UINT32 Bka1, Bke1, Bki1, Bko1, Bku1; \
    UINT32 Bma0, Bme0, Bmi0, Bmo0, Bmu0; \
    UINT32 Bma1, Bme1, Bmi1, Bmo1, Bmu1; \
    UINT32 Bsa0, Bse0, Bsi0, Bso0, Bsu0; \
    UINT32 Bsa1, Bse1, Bsi1, Bso1, Bsu1; \
    UINT32 Ca0, Ce0, Ci0, Co0, Cu0; \
    UINT32 Ca1, Ce1, Ci1, Co1, Cu1; \
    UINT32 Da0, De0, Di0, Do0, Du0; \
    UINT32 Da1, De1, Di1, Do1, Du1; \
    UINT32 Eba0, Ebe0, Ebi0, Ebo0, Ebu0; \
    UINT32 Eba1, Ebe1, Ebi1, Ebo1, Ebu1; \
    UINT32 Ega0, Ege0, Egi0, Ego0, Egu0; \
    UINT32 Ega1, Ege1, Egi1, Ego1, Egu1; \
    UINT32 Eka0, Eke0, Eki0, Eko0, Eku0; \
    UINT32 Eka1, Eke1, Eki1, Eko1, Eku1; \
    UINT32 Ema0, Eme0, Emi0, Emo0, Emu0; \
    UINT32 Ema1, Eme1, Emi1, Emo1, Emu1; \
    UINT32 Esa0, Ese0, Esi0, Eso0, Esu0; \
    UINT32 Esa1, Ese1, Esi1, Eso1, Esu1; \

#define prepareTheta \
    Ca0 = Aba0^Aga0^Aka0^Ama0^Asa0; \
    Ca1 = Aba1^Aga1^Aka1^Ama1^Asa1; \
    Ce0 = Abe0^Age0^Ake0^Ame0^Ase0; \
    Ce1 = Abe1^Age1^Ake1^Ame1^Ase1; \
    Ci0 = Abi0^Agi0^Aki0^Ami0^Asi0; \
    Ci1 = Abi1^Agi1^Aki1^Ami1^Asi1; \
    Co0 = Abo0^Ago0^Ako0^Amo0^Aso0; \
    Co1 = Abo1^Ago1^Ako1^Amo1^Aso1; \
    Cu0 = Abu0^Agu0^Aku0^Amu0^Asu0; \
    Cu1 = Abu1^Agu1^Aku1^Amu1^Asu1; \

#ifdef UseBebigokimisa
/*  --- Code for round, with prepare-theta (lane complementing pattern 'bebigokimisa') */
/*  --- using factor 2 interleaving, 64-bit lanes mapped to 32-bit words */
#define thetaRhoPiChiIotaPrepareTheta(i, A, E) \
    Da0 = Cu0^ROL32(Ce1, 1); \
    Da1 = Cu1^Ce0; \
    De0 = Ca0^ROL32(Ci1, 1); \
    De1 = Ca1^Ci0; \
    Di0 = Ce0^ROL32(Co1, 1); \
    Di1 = Ce1^Co0; \
    Do0 = Ci0^ROL32(Cu1, 1); \
    Do1 = Ci1^Cu0; \
    Du0 = Co0^ROL32(Ca1, 1); \
    Du1 = Co1^Ca0; \
\
    A##ba0 ^= Da0; \
    Bba0 = A##ba0; \
    A##ge0 ^= De0; \
    Bbe0 = ROL32(A##ge0, 22); \
    A##ki1 ^= Di1; \
    Bbi0 = ROL32(A##ki1, 22); \
    E##ba0 =   Bba0 ^(  Bbe0 |  Bbi0 ); \
    E##ba0 ^= KeccakF1600RoundConstants_int2_0[i]; \
    Ca0 = E##ba0; \
    A##mo1 ^= Do1; \
    Bbo0 = ROL32(A##mo1, 11); \
    E##be0 =   Bbe0 ^((~Bbi0)|  Bbo0 ); \
    Ce0 = E##be0; \
    A##su0 ^= Du0; \
    Bbu0 = ROL32(A##su0, 7); \
    E##bi0 =   Bbi0 ^(  Bbo0 &  Bbu0 ); \
    Ci0 = E##bi0; \
    E##bo0 =   Bbo0 ^(  Bbu0 |  Bba0 ); \
    Co0 = E##bo0; \
    E##bu0 =   Bbu0 ^(  Bba0 &  Bbe0 ); \
    Cu0 = E##bu0; \
\
    A##ba1 ^= Da1; \
    Bba1 = A##ba1; \
    A##ge1 ^= De1; \
    Bbe1 = ROL32(A##ge1, 22); \
    A##ki0 ^= Di0; \
    Bbi1 = ROL32(A##ki0, 21); \
    E##ba1 =   Bba1 ^(  Bbe1 |  Bbi1 ); \
    E##ba1 ^= KeccakF1600RoundConstants_int2_1[i]; \
    Ca1 = E##ba1; \
    A##mo0 ^= Do0; \
    Bbo1 = ROL32(A##mo0, 10); \
    E##be1 =   Bbe1 ^((~Bbi1)|  Bbo1 ); \
    Ce1 = E##be1; \
    A##su1 ^= Du1; \
    Bbu1 = ROL32(A##su1, 7); \
    E##bi1 =   Bbi1 ^(  Bbo1 &  Bbu1 ); \
    Ci1 = E##bi1; \
    E##bo1 =   Bbo1 ^(  Bbu1 |  Bba1 ); \
    Co1 = E##bo1; \
    E##bu1 =   Bbu1 ^(  Bba1 &  Bbe1 ); \
    Cu1 = E##bu1; \
\
    A##bo0 ^= Do0; \
    Bga0 = ROL32(A##bo0, 14); \
    A##gu0 ^= Du0; \
    Bge0 = ROL32(A##gu0, 10); \
    A##ka1 ^= Da1; \
    Bgi0 = ROL32(A##ka1, 2); \
    E##ga0 =   Bga0 ^(  Bge0 |  Bgi0 ); \
    Ca0 ^= E##ga0; \
    A##me1 ^= De1; \
    Bgo0 = ROL32(A##me1, 23); \
    E##ge0 =   Bge0 ^(  Bgi0 &  Bgo0 ); \
    Ce0 ^= E##ge0; \
    A##si1 ^= Di1; \
    Bgu0 = ROL32(A##si1, 31); \
    E##gi0 =   Bgi0 ^(  Bgo0 |(~Bgu0)); \
    Ci0 ^= E##gi0; \
    E##go0 =   Bgo0 ^(  Bgu0 |  Bga0 ); \
    Co0 ^= E##go0; \
    E##gu0 =   Bgu0 ^(  Bga0 &  Bge0 ); \
    Cu0 ^= E##gu0; \
\
    A##bo1 ^= Do1; \
    Bga1 = ROL32(A##bo1, 14); \
    A##gu1 ^= Du1; \
    Bge1 = ROL32(A##gu1, 10); \
    A##ka0 ^= Da0; \
    Bgi1 = ROL32(A##ka0, 1); \
    E##ga1 =   Bga1 ^(  Bge1 |  Bgi1 ); \
    Ca1 ^= E##ga1; \
    A##me0 ^= De0; \
    Bgo1 = ROL32(A##me0, 22); \
    E##ge1 =   Bge1 ^(  Bgi1 &  Bgo1 ); \
    Ce1 ^= E##ge1; \
    A##si0 ^= Di0; \
    Bgu1 = ROL32(A##si0, 30); \
    E##gi1 =   Bgi1 ^(  Bgo1 |(~Bgu1)); \
    Ci1 ^= E##gi1; \
    E##go1 =   Bgo1 ^(  Bgu1 |  Bga1 ); \
    Co1 ^= E##go1; \
    E##gu1 =   Bgu1 ^(  Bga1 &  Bge1 ); \
    Cu1 ^= E##gu1; \
\
    A##be1 ^= De1; \
    Bka0 = ROL32(A##be1, 1); \
    A##gi0 ^= Di0; \
    Bke0 = ROL32(A##gi0, 3); \
    A##ko1 ^= Do1; \
    Bki0 = ROL32(A##ko1, 13); \
    E##ka0 =   Bka0 ^(  Bke0 |  Bki0 ); \
    Ca0 ^= E##ka0; \
    A##mu0 ^= Du0; \
    Bko0 = ROL32(A##mu0, 4); \
    E##ke0 =   Bke0 ^(  Bki0 &  Bko0 ); \
    Ce0 ^= E##ke0; \
    A##sa0 ^= Da0; \
    Bku0 = ROL32(A##sa0, 9); \
    E##ki0 =   Bki0 ^((~Bko0)&  Bku0 ); \
    Ci0 ^= E##ki0; \
    E##ko0 = (~Bko0)^(  Bku0 |  Bka0 ); \
    Co0 ^= E##ko0; \
    E##ku0 =   Bku0 ^(  Bka0 &  Bke0 ); \
    Cu0 ^= E##ku0; \
\
    A##be0 ^= De0; \
    Bka1 = A##be0; \
    A##gi1 ^= Di1; \
    Bke1 = ROL32(A##gi1, 3); \
    A##ko0 ^= Do0; \
    Bki1 = ROL32(A##ko0, 12); \
    E##ka1 =   Bka1 ^(  Bke1 |  Bki1 ); \
    Ca1 ^= E##ka1; \
    A##mu1 ^= Du1; \
    Bko1 = ROL32(A##mu1, 4); \
    E##ke1 =   Bke1 ^(  Bki1 &  Bko1 ); \
    Ce1 ^= E##ke1; \
    A##sa1 ^= Da1; \
    Bku1 = ROL32(A##sa1, 9); \
    E##ki1 =   Bki1 ^((~Bko1)&  Bku1 ); \
    Ci1 ^= E##ki1; \
    E##ko1 = (~Bko1)^(  Bku1 |  Bka1 ); \
    Co1 ^= E##ko1; \
    E##ku1 =   Bku1 ^(  Bka1 &  Bke1 ); \
    Cu1 ^= E##ku1; \
\
    A##bu1 ^= Du1; \
    Bma0 = ROL32(A##bu1, 14); \
    A##ga0 ^= Da0; \
    Bme0 = ROL32(A##ga0, 18); \
    A##ke0 ^= De0; \
    Bmi0 = ROL32(A##ke0, 5); \
    E##ma0 =   Bma0 ^(  Bme0 &  Bmi0 ); \
    Ca0 ^= E##ma0; \
    A##mi1 ^= Di1; \
    Bmo0 = ROL32(A##mi1, 8); \
    E##me0 =   Bme0 ^(  Bmi0 |  Bmo0 ); \
    Ce0 ^= E##me0; \
    A##so0 ^= Do0; \
    Bmu0 = ROL32(A##so0, 28); \
    E##mi0 =   Bmi0 ^((~Bmo0)|  Bmu0 ); \
    Ci0 ^= E##mi0; \
    E##mo0 = (~Bmo0)^(  Bmu0 &  Bma0 ); \
    Co0 ^= E##mo0; \
    E##mu0 =   Bmu0 ^(  Bma0 |  Bme0 ); \
    Cu0 ^= E##mu0; \
\
    A##bu0 ^= Du0; \
    Bma1 = ROL32(A##bu0, 13); \
    A##ga1 ^= Da1; \
    Bme1 = ROL32(A##ga1, 18); \
    A##ke1 ^= De1; \
    Bmi1 = ROL32(A##ke1, 5); \
    E##ma1 =   Bma1 ^(  Bme1 &  Bmi1 ); \
    Ca1 ^= E##ma1; \
    A##mi0 ^= Di0; \
    Bmo1 = ROL32(A##mi0, 7); \
    E##me1 =   Bme1 ^(  Bmi1 |  Bmo1 ); \
    Ce1 ^= E##me1; \
    A##so1 ^= Do1; \
    Bmu1 = ROL32(A##so1, 28); \
    E##mi1 =   Bmi1 ^((~Bmo1)|  Bmu1 ); \
    Ci1 ^= E##mi1; \
    E##mo1 = (~Bmo1)^(  Bmu1 &  Bma1 ); \
    Co1 ^= E##mo1; \
    E##mu1 =   Bmu1 ^(  Bma1 |  Bme1 ); \
    Cu1 ^= E##mu1; \
\
    A##bi0 ^= Di0; \
    Bsa0 = ROL32(A##bi0, 31); \
    A##go1 ^= Do1; \
    Bse0 = ROL32(A##go1, 28); \
    A##ku1 ^= Du1; \
    Bsi0 = ROL32(A##ku1, 20); \
    E##sa0 =   Bsa0 ^((~Bse0)&  Bsi0 ); \
    Ca0 ^= E##sa0; \
    A##ma1 ^= Da1; \
    Bso0 = ROL32(A##ma1, 21); \
    E##se0 = (~Bse0)^(  Bsi0 |  Bso0 ); \
    Ce0 ^= E##se0; \
    A##se0 ^= De0; \
    Bsu0 = ROL32(A##se0, 1); \
    E##si0 =   Bsi0 ^(  Bso0 &  Bsu0 ); \
    Ci0 ^= E##si0; \
    E##so0 =   Bso0 ^(  Bsu0 |  Bsa0 ); \
    Co0 ^= E##so0; \
    E##su0 =   Bsu0 ^(  Bsa0 &  Bse0 ); \
    Cu0 ^= E##su0; \
\
    A##bi1 ^= Di1; \
    Bsa1 = ROL32(A##bi1, 31); \
    A##go0 ^= Do0; \
    Bse1 = ROL32(A##go0, 27); \
    A##ku0 ^= Du0; \
    Bsi1 = ROL32(A##ku0, 19); \
    E##sa1 =   Bsa1 ^((~Bse1)&  Bsi1 ); \
    Ca1 ^= E##sa1; \
    A##ma0 ^= Da0; \
    Bso1 = ROL32(A##ma0, 20); \
    E##se1 = (~Bse1)^(  Bsi1 |  Bso1 ); \
    Ce1 ^= E##se1; \
    A##se1 ^= De1; \
    Bsu1 = ROL32(A##se1, 1); \
    E##si1 =   Bsi1 ^(  Bso1 &  Bsu1 ); \
    Ci1 ^= E##si1; \
    E##so1 =   Bso1 ^(  Bsu1 |  Bsa1 ); \
    Co1 ^= E##so1; \
    E##su1 =   Bsu1 ^(  Bsa1 &  Bse1 ); \
    Cu1 ^= E##su1; \
\

/*  --- Code for round (lane complementing pattern 'bebigokimisa') */
/*  --- using factor 2 interleaving, 64-bit lanes mapped to 32-bit words */
#define thetaRhoPiChiIota(i, A, E) \
    Da0 = Cu0^ROL32(Ce1, 1); \
    Da1 = Cu1^Ce0; \
    De0 = Ca0^ROL32(Ci1, 1); \
    De1 = Ca1^Ci0; \
    Di0 = Ce0^ROL32(Co1, 1); \
    Di1 = Ce1^Co0; \
    Do0 = Ci0^ROL32(Cu1, 1); \
    Do1 = Ci1^Cu0; \
    Du0 = Co0^ROL32(Ca1, 1); \
    Du1 = Co1^Ca0; \
\
    A##ba0 ^= Da0; \
    Bba0 = A##ba0; \
    A##ge0 ^= De0; \
    Bbe0 = ROL32(A##ge0, 22); \
    A##ki1 ^= Di1; \
    Bbi0 = ROL32(A##ki1, 22); \
    E##ba0 =   Bba0 ^(  Bbe0 |  Bbi0 ); \
    E##ba0 ^= KeccakF1600RoundConstants_int2_0[i]; \
    A##mo1 ^= Do1; \
    Bbo0 = ROL32(A##mo1, 11); \
    E##be0 =   Bbe0 ^((~Bbi0)|  Bbo0 ); \
    A##su0 ^= Du0; \
    Bbu0 = ROL32(A##su0, 7); \
    E##bi0 =   Bbi0 ^(  Bbo0 &  Bbu0 ); \
    E##bo0 =   Bbo0 ^(  Bbu0 |  Bba0 ); \
    E##bu0 =   Bbu0 ^(  Bba0 &  Bbe0 ); \
\
    A##ba1 ^= Da1; \
    Bba1 = A##ba1; \
    A##ge1 ^= De1; \
    Bbe1 = ROL32(A##ge1, 22); \
    A##ki0 ^= Di0; \
    Bbi1 = ROL32(A##ki0, 21); \
    E##ba1 =   Bba1 ^(  Bbe1 |  Bbi1 ); \
    E##ba1 ^= KeccakF1600RoundConstants_int2_1[i]; \
    A##mo0 ^= Do0; \
    Bbo1 = ROL32(A##mo0, 10); \
    E##be1 =   Bbe1 ^((~Bbi1)|  Bbo1 ); \
    A##su1 ^= Du1; \
    Bbu1 = ROL32(A##su1, 7); \
    E##bi1 =   Bbi1 ^(  Bbo1 &  Bbu1 ); \
    E##bo1 =   Bbo1 ^(  Bbu1 |  Bba1 ); \
    E##bu1 =   Bbu1 ^(  Bba1 &  Bbe1 ); \
\
    A##bo0 ^= Do0; \
    Bga0 = ROL32(A##bo0, 14); \
    A##gu0 ^= Du0; \
    Bge0 = ROL32(A##gu0, 10); \
    A##ka1 ^= Da1; \
    Bgi0 = ROL32(A##ka1, 2); \
    E##ga0 =   Bga0 ^(  Bge0 |  Bgi0 ); \
    A##me1 ^= De1; \
    Bgo0 = ROL32(A##me1, 23); \
    E##ge0 =   Bge0 ^(  Bgi0 &  Bgo0 ); \
    A##si1 ^= Di1; \
    Bgu0 = ROL32(A##si1, 31); \
    E##gi0 =   Bgi0 ^(  Bgo0 |(~Bgu0)); \
    E##go0 =   Bgo0 ^(  Bgu0 |  Bga0 ); \
    E##gu0 =   Bgu0 ^(  Bga0 &  Bge0 ); \
\
    A##bo1 ^= Do1; \
    Bga1 = ROL32(A##bo1, 14); \
    A##gu1 ^= Du1; \
    Bge1 = ROL32(A##gu1, 10); \
    A##ka0 ^= Da0; \
    Bgi1 = ROL32(A##ka0, 1); \
    E##ga1 =   Bga1 ^(  Bge1 |  Bgi1 ); \
    A##me0 ^= De0; \
    Bgo1 = ROL32(A##me0, 22); \
    E##ge1 =   Bge1 ^(  Bgi1 &  Bgo1 ); \
    A##si0 ^= Di0; \
    Bgu1 = ROL32(A##si0, 30); \
    E##gi1 =   Bgi1 ^(  Bgo1 |(~Bgu1)); \
    E##go1 =   Bgo1 ^(  Bgu1 |  Bga1 ); \
    E##gu1 =   Bgu1 ^(  Bga1 &  Bge1 ); \
\
    A##be1 ^= De1; \
    Bka0 = ROL32(A##be1, 1); \
    A##gi0 ^= Di0; \
    Bke0 = ROL32(A##gi0, 3); \
    A##ko1 ^= Do1; \
    Bki0 = ROL32(A##ko1, 13); \
    E##ka0 =   Bka0 ^(  Bke0 |  Bki0 ); \
    A##mu0 ^= Du0; \
    Bko0 = ROL32(A##mu0, 4); \
    E##ke0 =   Bke0 ^(  Bki0 &  Bko0 ); \
    A##sa0 ^= Da0; \
    Bku0 = ROL32(A##sa0, 9); \
    E##ki0 =   Bki0 ^((~Bko0)&  Bku0 ); \
    E##ko0 = (~Bko0)^(  Bku0 |  Bka0 ); \
    E##ku0 =   Bku0 ^(  Bka0 &  Bke0 ); \
\
    A##be0 ^= De0; \
    Bka1 = A##be0; \
    A##gi1 ^= Di1; \
    Bke1 = ROL32(A##gi1, 3); \
    A##ko0 ^= Do0; \
    Bki1 = ROL32(A##ko0, 12); \
    E##ka1 =   Bka1 ^(  Bke1 |  Bki1 ); \
    A##mu1 ^= Du1; \
    Bko1 = ROL32(A##mu1, 4); \
    E##ke1 =   Bke1 ^(  Bki1 &  Bko1 ); \
    A##sa1 ^= Da1; \
    Bku1 = ROL32(A##sa1, 9); \
    E##ki1 =   Bki1 ^((~Bko1)&  Bku1 ); \
    E##ko1 = (~Bko1)^(  Bku1 |  Bka1 ); \
    E##ku1 =   Bku1 ^(  Bka1 &  Bke1 ); \
\
    A##bu1 ^= Du1; \
    Bma0 = ROL32(A##bu1, 14); \
    A##ga0 ^= Da0; \
    Bme0 = ROL32(A##ga0, 18); \
    A##ke0 ^= De0; \
    Bmi0 = ROL32(A##ke0, 5); \
    E##ma0 =   Bma0 ^(  Bme0 &  Bmi0 ); \
    A##mi1 ^= Di1; \
    Bmo0 = ROL32(A##mi1, 8); \
    E##me0 =   Bme0 ^(  Bmi0 |  Bmo0 ); \
    A##so0 ^= Do0; \
    Bmu0 = ROL32(A##so0, 28); \
    E##mi0 =   Bmi0 ^((~Bmo0)|  Bmu0 ); \
    E##mo0 = (~Bmo0)^(  Bmu0 &  Bma0 ); \
    E##mu0 =   Bmu0 ^(  Bma0 |  Bme0 ); \
\
    A##bu0 ^= Du0; \
    Bma1 = ROL32(A##bu0, 13); \
    A##ga1 ^= Da1; \
    Bme1 = ROL32(A##ga1, 18); \
    A##ke1 ^= De1; \
    Bmi1 = ROL32(A##ke1, 5); \
    E##ma1 =   Bma1 ^(  Bme1 &  Bmi1 ); \
    A##mi0 ^= Di0; \
    Bmo1 = ROL32(A##mi0, 7); \
    E##me1 =   Bme1 ^(  Bmi1 |  Bmo1 ); \
    A##so1 ^= Do1; \
    Bmu1 = ROL32(A##so1, 28); \
    E##mi1 =   Bmi1 ^((~Bmo1)|  Bmu1 ); \
    E##mo1 = (~Bmo1)^(  Bmu1 &  Bma1 ); \
    E##mu1 =   Bmu1 ^(  Bma1 |  Bme1 ); \
\
    A##bi0 ^= Di0; \
    Bsa0 = ROL32(A##bi0, 31); \
    A##go1 ^= Do1; \
    Bse0 = ROL32(A##go1, 28); \
    A##ku1 ^= Du1; \
    Bsi0 = ROL32(A##ku1, 20); \
    E##sa0 =   Bsa0 ^((~Bse0)&  Bsi0 ); \
    A##ma1 ^= Da1; \
    Bso0 = ROL32(A##ma1, 21); \
    E##se0 = (~Bse0)^(  Bsi0 |  Bso0 ); \
    A##se0 ^= De0; \
    Bsu0 = ROL32(A##se0, 1); \
    E##si0 =   Bsi0 ^(  Bso0 &  Bsu0 ); \
    E##so0 =   Bso0 ^(  Bsu0 |  Bsa0 ); \
    E##su0 =   Bsu0 ^(  Bsa0 &  Bse0 ); \
\
    A##bi1 ^= Di1; \
    Bsa1 = ROL32(A##bi1, 31); \
    A##go0 ^= Do0; \
    Bse1 = ROL32(A##go0, 27); \
    A##ku0 ^= Du0; \
    Bsi1 = ROL32(A##ku0, 19); \
    E##sa1 =   Bsa1 ^((~Bse1)&  Bsi1 ); \
    A##ma0 ^= Da0; \
    Bso1 = ROL32(A##ma0, 20); \
    E##se1 = (~Bse1)^(  Bsi1 |  Bso1 ); \
    A##se1 ^= De1; \
    Bsu1 = ROL32(A##se1, 1); \
    E##si1 =   Bsi1 ^(  Bso1 &  Bsu1 ); \
    E##so1 =   Bso1 ^(  Bsu1 |  Bsa1 ); \
    E##su1 =   Bsu1 ^(  Bsa1 &  Bse1 ); \
\

#else /*  UseBebigokimisa */
/*  --- Code for round, with prepare-theta */
/*  --- using factor 2 interleaving, 64-bit lanes mapped to 32-bit words */
#define thetaRhoPiChiIotaPrepareTheta(i, A, E) \
    Da0 = Cu0^ROL32(Ce1, 1); \
    Da1 = Cu1^Ce0; \
    De0 = Ca0^ROL32(Ci1, 1); \
    De1 = Ca1^Ci0; \
    Di0 = Ce0^ROL32(Co1, 1); \
    Di1 = Ce1^Co0; \
    Do0 = Ci0^ROL32(Cu1, 1); \
    Do1 = Ci1^Cu0; \
    Du0 = Co0^ROL32(Ca1, 1); \
    Du1 = Co1^Ca0; \
\
    A##ba0 ^= Da0; \
    Bba0 = A##ba0; \
    A##ge0 ^= De0; \
    Bbe0 = ROL32(A##ge0, 22); \
    A##ki1 ^= Di1; \
    Bbi0 = ROL32(A##ki1, 22); \
    E##ba0 =   Bba0 ^((~Bbe0)&  Bbi0 ); \
    E##ba0 ^= KeccakF1600RoundConstants_int2_0[i]; \
    Ca0 = E##ba0; \
    A##mo1 ^= Do1; \
    Bbo0 = ROL32(A##mo1, 11); \
    E##be0 =   Bbe0 ^((~Bbi0)&  Bbo0 ); \
    Ce0 = E##be0; \
    A##su0 ^= Du0; \
    Bbu0 = ROL32(A##su0, 7); \
    E##bi0 =   Bbi0 ^((~Bbo0)&  Bbu0 ); \
    Ci0 = E##bi0; \
    E##bo0 =   Bbo0 ^((~Bbu0)&  Bba0 ); \
    Co0 = E##bo0; \
    E##bu0 =   Bbu0 ^((~Bba0)&  Bbe0 ); \
    Cu0 = E##bu0; \
\
    A##ba1 ^= Da1; \
    Bba1 = A##ba1; \
    A##ge1 ^= De1; \
    Bbe1 = ROL32(A##ge1, 22); \
    A##ki0 ^= Di0; \
    Bbi1 = ROL32(A##ki0, 21); \
    E##ba1 =   Bba1 ^((~Bbe1)&  Bbi1 ); \
    E##ba1 ^= KeccakF1600RoundConstants_int2_1[i]; \
    Ca1 = E##ba1; \
    A##mo0 ^= Do0; \
    Bbo1 = ROL32(A##mo0, 10); \
    E##be1 =   Bbe1 ^((~Bbi1)&  Bbo1 ); \
    Ce1 = E##be1; \
    A##su1 ^= Du1; \
    Bbu1 = ROL32(A##su1, 7); \
    E##bi1 =   Bbi1 ^((~Bbo1)&  Bbu1 ); \
    Ci1 = E##bi1; \
    E##bo1 =   Bbo1 ^((~Bbu1)&  Bba1 ); \
    Co1 = E##bo1; \
    E##bu1 =   Bbu1 ^((~Bba1)&  Bbe1 ); \
    Cu1 = E##bu1; \
\
    A##bo0 ^= Do0; \
    Bga0 = ROL32(A##bo0, 14); \
    A##gu0 ^= Du0; \
    Bge0 = ROL32(A##gu0, 10); \
    A##ka1 ^= Da1; \
    Bgi0 = ROL32(A##ka1, 2); \
    E##ga0 =   Bga0 ^((~Bge0)&  Bgi0 ); \
    Ca0 ^= E##ga0; \
    A##me1 ^= De1; \
    Bgo0 = ROL32(A##me1, 23); \
    E##ge0 =   Bge0 ^((~Bgi0)&  Bgo0 ); \
    Ce0 ^= E##ge0; \
    A##si1 ^= Di1; \
    Bgu0 = ROL32(A##si1, 31); \
    E##gi0 =   Bgi0 ^((~Bgo0)&  Bgu0 ); \
    Ci0 ^= E##gi0; \
    E##go0 =   Bgo0 ^((~Bgu0)&  Bga0 ); \
    Co0 ^= E##go0; \
    E##gu0 =   Bgu0 ^((~Bga0)&  Bge0 ); \
    Cu0 ^= E##gu0; \
\
    A##bo1 ^= Do1; \
    Bga1 = ROL32(A##bo1, 14); \
    A##gu1 ^= Du1; \
    Bge1 = ROL32(A##gu1, 10); \
    A##ka0 ^= Da0; \
    Bgi1 = ROL32(A##ka0, 1); \
    E##ga1 =   Bga1 ^((~Bge1)&  Bgi1 ); \
    Ca1 ^= E##ga1; \
    A##me0 ^= De0; \
    Bgo1 = ROL32(A##me0, 22); \
    E##ge1 =   Bge1 ^((~Bgi1)&  Bgo1 ); \
    Ce1 ^= E##ge1; \
    A##si0 ^= Di0; \
    Bgu1 = ROL32(A##si0, 30); \
    E##gi1 =   Bgi1 ^((~Bgo1)&  Bgu1 ); \
    Ci1 ^= E##gi1; \
    E##go1 =   Bgo1 ^((~Bgu1)&  Bga1 ); \
    Co1 ^= E##go1; \
    E##gu1 =   Bgu1 ^((~Bga1)&  Bge1 ); \
    Cu1 ^= E##gu1; \
\
    A##be1 ^= De1; \
    Bka0 = ROL32(A##be1, 1); \
    A##gi0 ^= Di0; \
    Bke0 = ROL32(A##gi0, 3); \
    A##ko1 ^= Do1; \
    Bki0 = ROL32(A##ko1, 13); \
    E##ka0 =   Bka0 ^((~Bke0)&  Bki0 ); \
    Ca0 ^= E##ka0; \
    A##mu0 ^= Du0; \
    Bko0 = ROL32(A##mu0, 4); \
    E##ke0 =   Bke0 ^((~Bki0)&  Bko0 ); \
    Ce0 ^= E##ke0; \
    A##sa0 ^= Da0; \
    Bku0 = ROL32(A##sa0, 9); \
    E##ki0 =   Bki0 ^((~Bko0)&  Bku0 ); \
    Ci0 ^= E##ki0; \
    E##ko0 =   Bko0 ^((~Bku0)&  Bka0 ); \
    Co0 ^= E##ko0; \
    E##ku0 =   Bku0 ^((~Bka0)&  Bke0 ); \
    Cu0 ^= E##ku0; \
\
    A##be0 ^= De0; \
    Bka1 = A##be0; \
    A##gi1 ^= Di1; \
    Bke1 = ROL32(A##gi1, 3); \
    A##ko0 ^= Do0; \
    Bki1 = ROL32(A##ko0, 12); \
    E##ka1 =   Bka1 ^((~Bke1)&  Bki1 ); \
    Ca1 ^= E##ka1; \
    A##mu1 ^= Du1; \
    Bko1 = ROL32(A##mu1, 4); \
    E##ke1 =   Bke1 ^((~Bki1)&  Bko1 ); \
    Ce1 ^= E##ke1; \
    A##sa1 ^= Da1; \
    Bku1 = ROL32(A##sa1, 9); \
    E##ki1 =   Bki1 ^((~Bko1)&  Bku1 ); \
    Ci1 ^= E##ki1; \
    E##ko1 =   Bko1 ^((~Bku1)&  Bka1 ); \
    Co1 ^= E##ko1; \
    E##ku1 =   Bku1 ^((~Bka1)&  Bke1 ); \
    Cu1 ^= E##ku1; \
\
    A##bu1 ^= Du1; \
    Bma0 = ROL32(A##bu1, 14); \
    A##ga0 ^= Da0; \
    Bme0 = ROL32(A##ga0, 18); \
    A##ke0 ^= De0; \
    Bmi0 = ROL32(A##ke0, 5); \
    E##ma0 =   Bma0 ^((~Bme0)&  Bmi0 ); \
    Ca0 ^= E##ma0; \
    A##mi1 ^= Di1; \
    Bmo0 = ROL32(A##mi1, 8); \
    E##me0 =   Bme0 ^((~Bmi0)&  Bmo0 ); \
    Ce0 ^= E##me0; \
    A##so0 ^= Do0; \
    Bmu0 = ROL32(A##so0, 28); \
    E##mi0 =   Bmi0 ^((~Bmo0)&  Bmu0 ); \
    Ci0 ^= E##mi0; \
    E##mo0 =   Bmo0 ^((~Bmu0)&  Bma0 ); \
    Co0 ^= E##mo0; \
    E##mu0 =   Bmu0 ^((~Bma0)&  Bme0 ); \
    Cu0 ^= E##mu0; \
\
    A##bu0 ^= Du0; \
    Bma1 = ROL32(A##bu0, 13); \
    A##ga1 ^= Da1; \
    Bme1 = ROL32(A##ga1, 18); \
    A##ke1 ^= De1; \
    Bmi1 = ROL32(A##ke1, 5); \
    E##ma1 =   Bma1 ^((~Bme1)&  Bmi1 ); \
    Ca1 ^= E##ma1; \
    A##mi0 ^= Di0; \
    Bmo1 = ROL32(A##mi0, 7); \
    E##me1 =   Bme1 ^((~Bmi1)&  Bmo1 ); \
    Ce1 ^= E##me1; \
    A##so1 ^= Do1; \
    Bmu1 = ROL32(A##so1, 28); \
    E##mi1 =   Bmi1 ^((~Bmo1)&  Bmu1 ); \
    Ci1 ^= E##mi1; \
    E##mo1 =   Bmo1 ^((~Bmu1)&  Bma1 ); \
    Co1 ^= E##mo1; \
    E##mu1 =   Bmu1 ^((~Bma1)&  Bme1 ); \
    Cu1 ^= E##mu1; \
\
    A##bi0 ^= Di0; \
    Bsa0 = ROL32(A##bi0, 31); \
    A##go1 ^= Do1; \
    Bse0 = ROL32(A##go1, 28); \
    A##ku1 ^= Du1; \
    Bsi0 = ROL32(A##ku1, 20); \
    E##sa0 =   Bsa0 ^((~Bse0)&  Bsi0 ); \
    Ca0 ^= E##sa0; \
    A##ma1 ^= Da1; \
    Bso0 = ROL32(A##ma1, 21); \
    E##se0 =   Bse0 ^((~Bsi0)&  Bso0 ); \
    Ce0 ^= E##se0; \
    A##se0 ^= De0; \
    Bsu0 = ROL32(A##se0, 1); \
    E##si0 =   Bsi0 ^((~Bso0)&  Bsu0 ); \
    Ci0 ^= E##si0; \
    E##so0 =   Bso0 ^((~Bsu0)&  Bsa0 ); \
    Co0 ^= E##so0; \
    E##su0 =   Bsu0 ^((~Bsa0)&  Bse0 ); \
    Cu0 ^= E##su0; \
\
    A##bi1 ^= Di1; \
    Bsa1 = ROL32(A##bi1, 31); \
    A##go0 ^= Do0; \
    Bse1 = ROL32(A##go0, 27); \
    A##ku0 ^= Du0; \
    Bsi1 = ROL32(A##ku0, 19); \
    E##sa1 =   Bsa1 ^((~Bse1)&  Bsi1 ); \
    Ca1 ^= E##sa1; \
    A##ma0 ^= Da0; \
    Bso1 = ROL32(A##ma0, 20); \
    E##se1 =   Bse1 ^((~Bsi1)&  Bso1 ); \
    Ce1 ^= E##se1; \
    A##se1 ^= De1; \
    Bsu1 = ROL32(A##se1, 1); \
    E##si1 =   Bsi1 ^((~Bso1)&  Bsu1 ); \
    Ci1 ^= E##si1; \
    E##so1 =   Bso1 ^((~Bsu1)&  Bsa1 ); \
    Co1 ^= E##so1; \
    E##su1 =   Bsu1 ^((~Bsa1)&  Bse1 ); \
    Cu1 ^= E##su1; \
\

/*  --- Code for round */
/*  --- using factor 2 interleaving, 64-bit lanes mapped to 32-bit words */
#define thetaRhoPiChiIota(i, A, E) \
    Da0 = Cu0^ROL32(Ce1, 1); \
    Da1 = Cu1^Ce0; \
    De0 = Ca0^ROL32(Ci1, 1); \
    De1 = Ca1^Ci0; \
    Di0 = Ce0^ROL32(Co1, 1); \
    Di1 = Ce1^Co0; \
    Do0 = Ci0^ROL32(Cu1, 1); \
    Do1 = Ci1^Cu0; \
    Du0 = Co0^ROL32(Ca1, 1); \
    Du1 = Co1^Ca0; \
\
    A##ba0 ^= Da0; \
    Bba0 = A##ba0; \
    A##ge0 ^= De0; \
    Bbe0 = ROL32(A##ge0, 22); \
    A##ki1 ^= Di1; \
    Bbi0 = ROL32(A##ki1, 22); \
    E##ba0 =   Bba0 ^((~Bbe0)&  Bbi0 ); \
    E##ba0 ^= KeccakF1600RoundConstants_int2_0[i]; \
    A##mo1 ^= Do1; \
    Bbo0 = ROL32(A##mo1, 11); \
    E##be0 =   Bbe0 ^((~Bbi0)&  Bbo0 ); \
    A##su0 ^= Du0; \
    Bbu0 = ROL32(A##su0, 7); \
    E##bi0 =   Bbi0 ^((~Bbo0)&  Bbu0 ); \
    E##bo0 =   Bbo0 ^((~Bbu0)&  Bba0 ); \
    E##bu0 =   Bbu0 ^((~Bba0)&  Bbe0 ); \
\
    A##ba1 ^= Da1; \
    Bba1 = A##ba1; \
    A##ge1 ^= De1; \
    Bbe1 = ROL32(A##ge1, 22); \
    A##ki0 ^= Di0; \
    Bbi1 = ROL32(A##ki0, 21); \
    E##ba1 =   Bba1 ^((~Bbe1)&  Bbi1 ); \
    E##ba1 ^= KeccakF1600RoundConstants_int2_1[i]; \
    A##mo0 ^= Do0; \
    Bbo1 = ROL32(A##mo0, 10); \
    E##be1 =   Bbe1 ^((~Bbi1)&  Bbo1 ); \
    A##su1 ^= Du1; \
    Bbu1 = ROL32(A##su1, 7); \
    E##bi1 =   Bbi1 ^((~Bbo1)&  Bbu1 ); \
    E##bo1 =   Bbo1 ^((~Bbu1)&  Bba1 ); \
    E##bu1 =   Bbu1 ^((~Bba1)&  Bbe1 ); \
\
    A##bo0 ^= Do0; \
    Bga0 = ROL32(A##bo0, 14); \
    A##gu0 ^= Du0; \
    Bge0 = ROL32(A##gu0, 10); \
    A##ka1 ^= Da1; \
    Bgi0 = ROL32(A##ka1, 2); \
    E##ga0 =   Bga0 ^((~Bge0)&  Bgi0 ); \
    A##me1 ^= De1; \
    Bgo0 = ROL32(A##me1, 23); \
    E##ge0 =   Bge0 ^((~Bgi0)&  Bgo0 ); \
    A##si1 ^= Di1; \
    Bgu0 = ROL32(A##si1, 31); \
    E##gi0 =   Bgi0 ^((~Bgo0)&  Bgu0 ); \
    E##go0 =   Bgo0 ^((~Bgu0)&  Bga0 ); \
    E##gu0 =   Bgu0 ^((~Bga0)&  Bge0 ); \
\
    A##bo1 ^= Do1; \
    Bga1 = ROL32(A##bo1, 14); \
    A##gu1 ^= Du1; \
    Bge1 = ROL32(A##gu1, 10); \
    A##ka0 ^= Da0; \
    Bgi1 = ROL32(A##ka0, 1); \
    E##ga1 =   Bga1 ^((~Bge1)&  Bgi1 ); \
    A##me0 ^= De0; \
    Bgo1 = ROL32(A##me0, 22); \
    E##ge1 =   Bge1 ^((~Bgi1)&  Bgo1 ); \
    A##si0 ^= Di0; \
    Bgu1 = ROL32(A##si0, 30); \
    E##gi1 =   Bgi1 ^((~Bgo1)&  Bgu1 ); \
    E##go1 =   Bgo1 ^((~Bgu1)&  Bga1 ); \
    E##gu1 =   Bgu1 ^((~Bga1)&  Bge1 ); \
\
    A##be1 ^= De1; \
    Bka0 = ROL32(A##be1, 1); \
    A##gi0 ^= Di0; \
    Bke0 = ROL32(A##gi0, 3); \
    A##ko1 ^= Do1; \
    Bki0 = ROL32(A##ko1, 13); \
    E##ka0 =   Bka0 ^((~Bke0)&  Bki0 ); \
    A##mu0 ^= Du0; \
    Bko0 = ROL32(A##mu0, 4); \
    E##ke0 =   Bke0 ^((~Bki0)&  Bko0 ); \
    A##sa0 ^= Da0; \
    Bku0 = ROL32(A##sa0, 9); \
    E##ki0 =   Bki0 ^((~Bko0)&  Bku0 ); \
    E##ko0 =   Bko0 ^((~Bku0)&  Bka0 ); \
    E##ku0 =   Bku0 ^((~Bka0)&  Bke0 ); \
\
    A##be0 ^= De0; \
    Bka1 = A##be0; \
    A##gi1 ^= Di1; \
    Bke1 = ROL32(A##gi1, 3); \
    A##ko0 ^= Do0; \
    Bki1 = ROL32(A##ko0, 12); \
    E##ka1 =   Bka1 ^((~Bke1)&  Bki1 ); \
    A##mu1 ^= Du1; \
    Bko1 = ROL32(A##mu1, 4); \
    E##ke1 =   Bke1 ^((~Bki1)&  Bko1 ); \
    A##sa1 ^= Da1; \
    Bku1 = ROL32(A##sa1, 9); \
    E##ki1 =   Bki1 ^((~Bko1)&  Bku1 ); \
    E##ko1 =   Bko1 ^((~Bku1)&  Bka1 ); \
    E##ku1 =   Bku1 ^((~Bka1)&  Bke1 ); \
\
    A##bu1 ^= Du1; \
    Bma0 = ROL32(A##bu1, 14); \
    A##ga0 ^= Da0; \
    Bme0 = ROL32(A##ga0, 18); \
    A##ke0 ^= De0; \
    Bmi0 = ROL32(A##ke0, 5); \
    E##ma0 =   Bma0 ^((~Bme0)&  Bmi0 ); \
    A##mi1 ^= Di1; \
    Bmo0 = ROL32(A##mi1, 8); \
    E##me0 =   Bme0 ^((~Bmi0)&  Bmo0 ); \
    A##so0 ^= Do0; \
    Bmu0 = ROL32(A##so0, 28); \
    E##mi0 =   Bmi0 ^((~Bmo0)&  Bmu0 ); \
    E##mo0 =   Bmo0 ^((~Bmu0)&  Bma0 ); \
    E##mu0 =   Bmu0 ^((~Bma0)&  Bme0 ); \
\
    A##bu0 ^= Du0; \
    Bma1 = ROL32(A##bu0, 13); \
    A##ga1 ^= Da1; \
    Bme1 = ROL32(A##ga1, 18); \
    A##ke1 ^= De1; \
    Bmi1 = ROL32(A##ke1, 5); \
    E##ma1 =   Bma1 ^((~Bme1)&  Bmi1 ); \
    A##mi0 ^= Di0; \
    Bmo1 = ROL32(A##mi0, 7); \
    E##me1 =   Bme1 ^((~Bmi1)&  Bmo1 ); \
    A##so1 ^= Do1; \
    Bmu1 = ROL32(A##so1, 28); \
    E##mi1 =   Bmi1 ^((~Bmo1)&  Bmu1 ); \
    E##mo1 =   Bmo1 ^((~Bmu1)&  Bma1 ); \
    E##mu1 =   Bmu1 ^((~Bma1)&  Bme1 ); \
\
    A##bi0 ^= Di0; \
    Bsa0 = ROL32(A##bi0, 31); \
    A##go1 ^= Do1; \
    Bse0 = ROL32(A##go1, 28); \
    A##ku1 ^= Du1; \
    Bsi0 = ROL32(A##ku1, 20); \
    E##sa0 =   Bsa0 ^((~Bse0)&  Bsi0 ); \
    A##ma1 ^= Da1; \
    Bso0 = ROL32(A##ma1, 21); \
    E##se0 =   Bse0 ^((~Bsi0)&  Bso0 ); \
    A##se0 ^= De0; \
    Bsu0 = ROL32(A##se0, 1); \
    E##si0 =   Bsi0 ^((~Bso0)&  Bsu0 ); \
    E##so0 =   Bso0 ^((~Bsu0)&  Bsa0 ); \
    E##su0 =   Bsu0 ^((~Bsa0)&  Bse0 ); \
\
    A##bi1 ^= Di1; \
    Bsa1 = ROL32(A##bi1, 31); \
    A##go0 ^= Do0; \
    Bse1 = ROL32(A##go0, 27); \
    A##ku0 ^= Du0; \
    Bsi1 = ROL32(A##ku0, 19); \
    E##sa1 =   Bsa1 ^((~Bse1)&  Bsi1 ); \
    A##ma0 ^= Da0; \
    Bso1 = ROL32(A##ma0, 20); \
    E##se1 =   Bse1 ^((~Bsi1)&  Bso1 ); \
    A##se1 ^= De1; \
    Bsu1 = ROL32(A##se1, 1); \
    E##si1 =   Bsi1 ^((~Bso1)&  Bsu1 ); \
    E##so1 =   Bso1 ^((~Bsu1)&  Bsa1 ); \
    E##su1 =   Bsu1 ^((~Bsa1)&  Bse1 ); \
\

#endif /*  UseBebigokimisa */

#define copyFromStateAndXor1024bits(X, state, input) \
    X##ba0 = state[ 0]^input[ 0]; \
    X##ba1 = state[ 1]^input[ 1]; \
    X##be0 = state[ 2]^input[ 2]; \
    X##be1 = state[ 3]^input[ 3]; \
    X##bi0 = state[ 4]^input[ 4]; \
    X##bi1 = state[ 5]^input[ 5]; \
    X##bo0 = state[ 6]^input[ 6]; \
    X##bo1 = state[ 7]^input[ 7]; \
    X##bu0 = state[ 8]^input[ 8]; \
    X##bu1 = state[ 9]^input[ 9]; \
    X##ga0 = state[10]^input[10]; \
    X##ga1 = state[11]^input[11]; \
    X##ge0 = state[12]^input[12]; \
    X##ge1 = state[13]^input[13]; \
    X##gi0 = state[14]^input[14]; \
    X##gi1 = state[15]^input[15]; \
    X##go0 = state[16]^input[16]; \
    X##go1 = state[17]^input[17]; \
    X##gu0 = state[18]^input[18]; \
    X##gu1 = state[19]^input[19]; \
    X##ka0 = state[20]^input[20]; \
    X##ka1 = state[21]^input[21]; \
    X##ke0 = state[22]^input[22]; \
    X##ke1 = state[23]^input[23]; \
    X##ki0 = state[24]^input[24]; \
    X##ki1 = state[25]^input[25]; \
    X##ko0 = state[26]^input[26]; \
    X##ko1 = state[27]^input[27]; \
    X##ku0 = state[28]^input[28]; \
    X##ku1 = state[29]^input[29]; \
    X##ma0 = state[30]^input[30]; \
    X##ma1 = state[31]^input[31]; \
    X##me0 = state[32]; \
    X##me1 = state[33]; \
    X##mi0 = state[34]; \
    X##mi1 = state[35]; \
    X##mo0 = state[36]; \
    X##mo1 = state[37]; \
    X##mu0 = state[38]; \
    X##mu1 = state[39]; \
    X##sa0 = state[40]; \
    X##sa1 = state[41]; \
    X##se0 = state[42]; \
    X##se1 = state[43]; \
    X##si0 = state[44]; \
    X##si1 = state[45]; \
    X##so0 = state[46]; \
    X##so1 = state[47]; \
    X##su0 = state[48]; \
    X##su1 = state[49]; \

#define copyFromStateAndXor1088bits(X, state, input) \
    X##ba0 = state[ 0]^input[ 0]; \
    X##ba1 = state[ 1]^input[ 1]; \
    X##be0 = state[ 2]^input[ 2]; \
    X##be1 = state[ 3]^input[ 3]; \
    X##bi0 = state[ 4]^input[ 4]; \
    X##bi1 = state[ 5]^input[ 5]; \
    X##bo0 = state[ 6]^input[ 6]; \
    X##bo1 = state[ 7]^input[ 7]; \
    X##bu0 = state[ 8]^input[ 8]; \
    X##bu1 = state[ 9]^input[ 9]; \
    X##ga0 = state[10]^input[10]; \
    X##ga1 = state[11]^input[11]; \
    X##ge0 = state[12]^input[12]; \
    X##ge1 = state[13]^input[13]; \
    X##gi0 = state[14]^input[14]; \
    X##gi1 = state[15]^input[15]; \
    X##go0 = state[16]^input[16]; \
    X##go1 = state[17]^input[17]; \
    X##gu0 = state[18]^input[18]; \
    X##gu1 = state[19]^input[19]; \
    X##ka0 = state[20]^input[20]; \
    X##ka1 = state[21]^input[21]; \
    X##ke0 = state[22]^input[22]; \
    X##ke1 = state[23]^input[23]; \
    X##ki0 = state[24]^input[24]; \
    X##ki1 = state[25]^input[25]; \
    X##ko0 = state[26]^input[26]; \
    X##ko1 = state[27]^input[27]; \
    X##ku0 = state[28]^input[28]; \
    X##ku1 = state[29]^input[29]; \
    X##ma0 = state[30]^input[30]; \
    X##ma1 = state[31]^input[31]; \
    X##me0 = state[32]^input[32]; \
    X##me1 = state[33]^input[33]; \
    X##mi0 = state[34]; \
    X##mi1 = state[35]; \
    X##mo0 = state[36]; \
    X##mo1 = state[37]; \
    X##mu0 = state[38]; \
    X##mu1 = state[39]; \
    X##sa0 = state[40]; \
    X##sa1 = state[41]; \
    X##se0 = state[42]; \
    X##se1 = state[43]; \
    X##si0 = state[44]; \
    X##si1 = state[45]; \
    X##so0 = state[46]; \
    X##so1 = state[47]; \
    X##su0 = state[48]; \
    X##su1 = state[49]; \

#define copyFromState(X, state) \
    X##ba0 = state[ 0]; \
    X##ba1 = state[ 1]; \
    X##be0 = state[ 2]; \
    X##be1 = state[ 3]; \
    X##bi0 = state[ 4]; \
    X##bi1 = state[ 5]; \
    X##bo0 = state[ 6]; \
    X##bo1 = state[ 7]; \
    X##bu0 = state[ 8]; \
    X##bu1 = state[ 9]; \
    X##ga0 = state[10]; \
    X##ga1 = state[11]; \
    X##ge0 = state[12]; \
    X##ge1 = state[13]; \
    X##gi0 = state[14]; \
    X##gi1 = state[15]; \
    X##go0 = state[16]; \
    X##go1 = state[17]; \
    X##gu0 = state[18]; \
    X##gu1 = state[19]; \
    X##ka0 = state[20]; \
    X##ka1 = state[21]; \
    X##ke0 = state[22]; \
    X##ke1 = state[23]; \
    X##ki0 = state[24]; \
    X##ki1 = state[25]; \
    X##ko0 = state[26]; \
    X##ko1 = state[27]; \
    X##ku0 = state[28]; \
    X##ku1 = state[29]; \
    X##ma0 = state[30]; \
    X##ma1 = state[31]; \
    X##me0 = state[32]; \
    X##me1 = state[33]; \
    X##mi0 = state[34]; \
    X##mi1 = state[35]; \
    X##mo0 = state[36]; \
    X##mo1 = state[37]; \
    X##mu0 = state[38]; \
    X##mu1 = state[39]; \
    X##sa0 = state[40]; \
    X##sa1 = state[41]; \
    X##se0 = state[42]; \
    X##se1 = state[43]; \
    X##si0 = state[44]; \
    X##si1 = state[45]; \
    X##so0 = state[46]; \
    X##so1 = state[47]; \
    X##su0 = state[48]; \
    X##su1 = state[49]; \

#define copyToState(state, X) \
    state[ 0] = X##ba0; \
    state[ 1] = X##ba1; \
    state[ 2] = X##be0; \
    state[ 3] = X##be1; \
    state[ 4] = X##bi0; \
    state[ 5] = X##bi1; \
    state[ 6] = X##bo0; \
    state[ 7] = X##bo1; \
    state[ 8] = X##bu0; \
    state[ 9] = X##bu1; \
    state[10] = X##ga0; \
    state[11] = X##ga1; \
    state[12] = X##ge0; \
    state[13] = X##ge1; \
    state[14] = X##gi0; \
    state[15] = X##gi1; \
    state[16] = X##go0; \
    state[17] = X##go1; \
    state[18] = X##gu0; \
    state[19] = X##gu1; \
    state[20] = X##ka0; \
    state[21] = X##ka1; \
    state[22] = X##ke0; \
    state[23] = X##ke1; \
    state[24] = X##ki0; \
    state[25] = X##ki1; \
    state[26] = X##ko0; \
    state[27] = X##ko1; \
    state[28] = X##ku0; \
    state[29] = X##ku1; \
    state[30] = X##ma0; \
    state[31] = X##ma1; \
    state[32] = X##me0; \
    state[33] = X##me1; \
    state[34] = X##mi0; \
    state[35] = X##mi1; \
    state[36] = X##mo0; \
    state[37] = X##mo1; \
    state[38] = X##mu0; \
    state[39] = X##mu1; \
    state[40] = X##sa0; \
    state[41] = X##sa1; \
    state[42] = X##se0; \
    state[43] = X##se1; \
    state[44] = X##si0; \
    state[45] = X##si1; \
    state[46] = X##so0; \
    state[47] = X##so1; \
    state[48] = X##su0; \
    state[49] = X##su1; \

#define copyStateVariables(X, Y) \
    X##ba0 = Y##ba0; \
    X##ba1 = Y##ba1; \
    X##be0 = Y##be0; \
    X##be1 = Y##be1; \
    X##bi0 = Y##bi0; \
    X##bi1 = Y##bi1; \
    X##bo0 = Y##bo0; \
    X##bo1 = Y##bo1; \
    X##bu0 = Y##bu0; \
    X##bu1 = Y##bu1; \
    X##ga0 = Y##ga0; \
    X##ga1 = Y##ga1; \
    X##ge0 = Y##ge0; \
    X##ge1 = Y##ge1; \
    X##gi0 = Y##gi0; \
    X##gi1 = Y##gi1; \
    X##go0 = Y##go0; \
    X##go1 = Y##go1; \
    X##gu0 = Y##gu0; \
    X##gu1 = Y##gu1; \
    X##ka0 = Y##ka0; \
    X##ka1 = Y##ka1; \
    X##ke0 = Y##ke0; \
    X##ke1 = Y##ke1; \
    X##ki0 = Y##ki0; \
    X##ki1 = Y##ki1; \
    X##ko0 = Y##ko0; \
    X##ko1 = Y##ko1; \
    X##ku0 = Y##ku0; \
    X##ku1 = Y##ku1; \
    X##ma0 = Y##ma0; \
    X##ma1 = Y##ma1; \
    X##me0 = Y##me0; \
    X##me1 = Y##me1; \
    X##mi0 = Y##mi0; \
    X##mi1 = Y##mi1; \
    X##mo0 = Y##mo0; \
    X##mo1 = Y##mo1; \
    X##mu0 = Y##mu0; \
    X##mu1 = Y##mu1; \
    X##sa0 = Y##sa0; \
    X##sa1 = Y##sa1; \
    X##se0 = Y##se0; \
    X##se1 = Y##se1; \
    X##si0 = Y##si0; \
    X##si1 = Y##si1; \
    X##so0 = Y##so0; \
    X##so1 = Y##so1; \
    X##su0 = Y##su0; \
    X##su1 = Y##su1; \


#endif