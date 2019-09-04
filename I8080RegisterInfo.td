class I8080Reg<bits<16> Enc, string n> : Register<n> {
  let HWEncoding = Enc;
  let Namespace = "I8080";
}

def I8080LowerReg: SubRegIndex<8, 0>;
def I8080UpperReg: SubRegIndex<8, 8>;

def regB : I8080Reg<0, "b">;
def regC : I8080Reg<1, "c">;
def regD : I8080Reg<2, "d">;
def regE : I8080Reg<3, "e">;
def regH : I8080Reg<4, "h">;
def regL : I8080Reg<5, "l">;
def regM : I8080Reg<6, "m">;
def regA : I8080Reg<7, "a">;

let CoveredBySubRegs = 1 in {
def regBC : I8080Reg<0, "bc"> {
  let SubRegs = [regB, regC];
  let SubRegIndices = [I8080UpperReg, I8080LowerReg];
}
def regDE : I8080Reg<1, "de"> {
  let SubRegs = [regD, regE];
  let SubRegIndices = [I8080UpperReg, I8080LowerReg];
}
def regHL : I8080Reg<2, "hl"> {
  let SubRegs = [regH, regL];
  let SubRegIndices = [I8080UpperReg, I8080LowerReg];
}
}
def regSP : I8080Reg<3, "sp">;

def AccReg: RegisterClass<"I8080", [i8], 8, (add regA)>;

def GPReg: RegisterClass<"I8080", [i8], 8,
( add regA, regB, regC, regD, regE, regH, regL, regM
)>;

def RPReg : RegisterClass<"I8080", [i16], 16,
( add regBC, regDE, regHL, regSP
)>;