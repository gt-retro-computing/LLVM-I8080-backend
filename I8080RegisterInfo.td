class I8080Reg<bits<16> Enc, string n> : Register<n> {
  let HWEncoding = Enc;
  let Namespace = "I8080";
}

let Namespace = "I8080" in {
    def zero : I8080Reg<0, "$zero">;
    def at: I8080Reg<1, "$at">;
    def v0: I8080Reg<2, "$v0">;
    def a0 : I8080Reg<3, "$a0">;
    def a1 : I8080Reg<4, "$a1">;
    def a2 : I8080Reg<5, "$a2">;
    def t0 : I8080Reg<6, "$t0">;
    def t1 : I8080Reg<7, "$t1">;
    def t2 : I8080Reg<8, "$t2">;
    def s0 : I8080Reg<9, "$s0">;
    def s1 : I8080Reg<10, "$s1">;
    def s2 : I8080Reg<11, "$s2">;
    def k0: I8080Reg<12, "$k0">;
    def sp: I8080Reg<13, "$sp">;
    def fp: I8080Reg<14, "$fp">;
    def ra: I8080Reg<15, "$ra">;
    def pc: I8080Reg<16, "$pc">;
}

def GRRegs : RegisterClass<"I8080", [i32], 32,
( add zero, at, v0, 
a0, a1, a2, 
t0, t1, t2,
s0, s1, s2,
k0, 
sp, // Stack Pointer
fp, // Frame Pointer
ra  // Return Address
)>;

def SRCRegs : RegisterClass<"I8080", [i32], 32,
( add zero, at, v0, 
a0, a1, a2, 
t0, t1, t2,
s0, s1, s2, 
k0, 
sp, // Stack Pointer
fp, // Frame Pointer
ra  // Return Address
)>;