{\rtf1\ansi\ansicpg949\cocoartf2580
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fmodern\fcharset0 Courier;\f1\fmodern\fcharset0 Courier-Oblique;\f2\fnil\fcharset129 AppleSDGothicNeo-Regular;
\f3\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red191\green100\blue38;\red32\green32\blue32;\red153\green168\blue186;
\red254\green187\blue91;\red133\green96\blue154;\red88\green118\blue71;\red41\green50\blue40;\red86\green132\blue173;
\red109\green109\blue109;}
{\*\expandedcolortbl;;\csgenericrgb\c74902\c39216\c14902;\csgenericrgb\c12549\c12549\c12549;\csgenericrgb\c60000\c65882\c72941;
\csgenericrgb\c99608\c73333\c35686;\csgenericrgb\c52157\c37647\c60392;\csgenericrgb\c34510\c46275\c27843;\csgenericrgb\c16078\c19608\c15686;\csgenericrgb\c33725\c51765\c67843;
\csgenericrgb\c42745\c42745\c42745;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx560\tx1120\tx1680\tx2240\tx2800\tx3360\tx3920\tx4480\tx5040\tx5600\tx6160\tx6720\pardirnatural\partightenfactor0

\f0\fs26 \cf2 \cb3 import \cf4 java.io.BufferedReader\cf2 ;\
import \cf4 java.io.IOException\cf2 ;\
import \cf4 java.io.InputStreamReader\cf2 ;\
public class \cf4 Main \{\
    \cf2 public static void \cf5 main\cf4 (String[] args) \cf2 throws \cf4 IOException \{\
        BufferedReader br = \cf2 new \cf4 BufferedReader(\cf2 new \cf4 InputStreamReader(System.
\f1\i \cf6 in
\f0\i0 \cf4 ))\cf2 ;\
        \cf4 String[] input = br.readLine().split(\cf7 "\cb8  \cb3 "\cf4 )\cf2 ;\
        int \cf4 n = Integer.
\f1\i parseInt
\f0\i0 (input[\cf9 0\cf4 ])\cf2 ;\
        int \cf4 k = Integer.
\f1\i parseInt
\f0\i0 (input[\cf9 1\cf4 ])\cf2 ;\
        \cf10 // i
\f2 \'bf\'f8\'c0\'bb
\f3  
\f2 \'c5\'eb\'c7\'d8
\f0  j
\f2 \'bf\'f8\'c0\'bb
\f3  
\f2 \'b8\'b8\'b5\'e9\'bc\'f6
\f3  
\f2 \'c0\'d6\'b4\'c2
\f3  
\f2 \'b0\'e6\'bf\'ec\'c0\'c7\'bc\'f6
\f3 \
        
\f0 \cf2 int\cf4 [] dp = \cf2 new int\cf4 [k+\cf9 1\cf4 ]\cf2 ;\
        for \cf4 (\cf2 int \cf4 i = \cf9 0\cf2 ; \cf4 i < n\cf2 ; \cf4 i++) \{\
            \cf2 int \cf4 coin = Integer.
\f1\i parseInt
\f0\i0 (br.readLine())\cf2 ;\
            for \cf4 (\cf2 int \cf4 j = \cf9 1\cf2 ; \cf4 j <= k\cf2 ; \cf4 j++) \{\
                \cf2 if \cf4 (j - coin > \cf9 0\cf4 ) \{\
                    \cf10 // j
\f2 \'bf\'f8
\f0 -coin
\f2 \'bf\'f8
\f3  
\f2 \'b0\'e6\'bf\'ec\'c0\'c7\'bc\'f6
\f0   + coin
\f2 \'bf\'f8
\f3  
\f2 \'b0\'e6\'bf\'ec\'c0\'c7\'bc\'f6
\f3  
\f2 \'c7\'d5
\f3 \
                    
\f0 \cf4 dp[j]+= dp[j-coin]\cf2 ;\
\
                    \cf10 // j
\f2 \'bf\'f8
\f3  
\f2 \'c7\'d8\'b4\'e7
\f3  
\f2 \'c4\'da\'c0\'ce\'c0\'b8\'b7\'ce
\f3  
\f2 \'b8\'b8\'b5\'e9
\f3  
\f2 \'bc\'f6
\f3  
\f2 \'c0\'d6\'c0\'b8\'b8\'e9
\f3  
\f2 \'b0\'e6\'bf\'ec\'c0\'c7
\f3  
\f2 \'bc\'f6
\f0  1 
\f2 \'c3\'df\'b0\'a1
\f3 \
                
\f0 \cf4 \} \cf2 else if \cf4 (j - coin == \cf9 0\cf4 ) \{\
                    dp[j]++\cf2 ;\
                \cf4 \}\
            \}\
        \}\
        System.
\f1\i \cf6 out
\f0\i0 \cf4 .println(dp[k])\cf2 ;\
    \cf4 \}\
\}\
}