; Inno Setup scriptas Windows installer failui.
; Sis failas turi buti pagrindiniame projekto aplanke.
; Pries Compile programa turi buti: dist\programa.exe

[Setup]
<<<<<<< Updated upstream
<<<<<<< Updated upstream
AppId=Objektinis3-Studentu_Ivedimas_AV
AppName=Studentu_Ivedimas_AV
AppVersion=1.0
DefaultDirName={pf}\VU\Studentu_Ivedimas_AV
DefaultGroupName=VU\Studentu_Ivedimas_AV
=======
=======
>>>>>>> Stashed changes
AppId=Objektinis3-Vardenis-Pavardenis
AppName=Vardenis-Pavardenis
AppVersion=1.0
DefaultDirName={pf}\VU\Vardenis-Pavardenis
DefaultGroupName=VU\Vardenis-Pavardenis
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
<<<<<<< Updated upstream
Name: "{group}\Studentu_Ivedimas_AV"; Filename: "{app}\programa.exe"; WorkingDir: "{app}"
Name: "{userdesktop}\Studentu_Ivedimas_AV"; Filename: "{app}\programa.exe"; WorkingDir: "{app}"
=======
Name: "{group}\Vardenis-Pavardenis"; Filename: "{app}\programa.exe"; WorkingDir: "{app}"
Name: "{userdesktop}\Vardenis-Pavardenis"; Filename: "{app}\programa.exe"; WorkingDir: "{app}"
>>>>>>> Stashed changes
=======
Name: "{group}\Vardenis-Pavardenis"; Filename: "{app}\programa.exe"; WorkingDir: "{app}"
Name: "{userdesktop}\Vardenis-Pavardenis"; Filename: "{app}\programa.exe"; WorkingDir: "{app}"
>>>>>>> Stashed changes

[Registry]
Root: HKLM; Subkey: "Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers"; ValueType: string; ValueName: "{app}\programa.exe"; ValueData: "RUNASADMIN"; Flags: uninsdeletevalue

[Run]
<<<<<<< Updated upstream
<<<<<<< Updated upstream
Filename: "{app}\programa.exe"; Description: "Paleisti Studentu_Ivedimas_AV"; Flags: nowait postinstall skipifsilent
=======
Filename: "{app}\programa.exe"; Description: "Paleisti Vardenis-Pavardenis"; Flags: nowait postinstall skipifsilent
>>>>>>> Stashed changes
=======
Filename: "{app}\programa.exe"; Description: "Paleisti Vardenis-Pavardenis"; Flags: nowait postinstall skipifsilent
>>>>>>> Stashed changes
