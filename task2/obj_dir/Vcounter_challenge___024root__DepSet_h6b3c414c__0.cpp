// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcounter_challenge.h for the primary calling header

#include "verilated.h"

#include "Vcounter_challenge___024root.h"

VL_INLINE_OPT void Vcounter_challenge___024root___sequent__TOP__0(Vcounter_challenge___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_challenge__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_challenge___024root___sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vdly__count;
    // Body
    __Vdly__count = vlSelf->count;
    if (vlSelf->rst) {
        __Vdly__count = 0U;
    } else if (vlSelf->en) {
        __Vdly__count = (0xffU & ((IData)(vlSelf->count) 
                                  + (IData)(vlSelf->en)));
    } else if ((1U & (~ (IData)(vlSelf->en)))) {
        __Vdly__count = (0xffU & ((IData)(vlSelf->count) 
                                  - (IData)(1U)));
    }
    vlSelf->count = __Vdly__count;
}

void Vcounter_challenge___024root___eval(Vcounter_challenge___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_challenge__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_challenge___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->en) & (~ (IData)(vlSelf->__Vclklast__TOP__en))))) {
        Vcounter_challenge___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__en = vlSelf->en;
}

#ifdef VL_DEBUG
void Vcounter_challenge___024root___eval_debug_assertions(Vcounter_challenge___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_challenge__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_challenge___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
