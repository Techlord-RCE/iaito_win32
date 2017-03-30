:: Put libr_*.dll in this directory
:: Put gendef.exe in PATH
:: Put MSVC2013 in PATH
@echo off
del *.def
del *.lib
del *.exp
for %%f in (*.dll) do gendef %%f
for %%f in (*.def) do lib /def:%%f /MACHINE:X86
del *.exp
del *.def
removePrefix lib *.lib