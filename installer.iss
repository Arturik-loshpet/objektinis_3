; Inno Setup scriptas Windows installer failui.
; Sis failas turi buti pagrindiniame projekto aplanke.
; Pries Compile programa turi buti: dist\programa.exe

[Setup]
AppId=Objektinis3-Studentu_Ivedimas_AV
AppName=Studentu_Ivedimas_AV
AppVersion=1.0
DefaultDirName={pf}\VU\Studentu_Ivedimas_AV
DefaultGroupName=VU\Studentu_Ivedimas_AV
OutputDir=installer
OutputBaseFilename=Setup
Compression=lzma
SolidCompression=yes
PrivilegesRequired=admin
DisableProgramGroupPage=yes

[Files]
Source: "dist\programa.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "dist\studentai10000.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "dist\studentai100000.txt"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{group}\Studentu_Ivedimas_AV"; Filename: "{app}\programa.exe"; WorkingDir: "{app}"
Name: "{userdesktop}\Studentu_Ivedimas_AV"; Filename: "{app}\programa.exe"; WorkingDir: "{app}"

[Registry]
Root: HKLM; Subkey: "Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers"; ValueType: string; ValueName: "{app}\programa.exe"; ValueData: "RUNASADMIN"; Flags: uninsdeletevalue

[Run]
Filename: "{app}\programa.exe"; Description: "Paleisti Studentu_Ivedimas_AV"; Flags: nowait postinstall skipifsilent
