; Inno Setup scriptas Windows installer failui.
; Sis failas turi buti pagrindiniame projekto aplanke.
; Pries Compile programa turi buti: dist\programa.exe

[Setup]
AppId=Objektinis3-Vardenis-Pavardenis
AppName=Vardenis-Pavardenis
AppVersion=1.0
DefaultDirName={pf}\VU\Vardenis-Pavardenis
DefaultGroupName=VU\Vardenis-Pavardenis
OutputDir=installer
OutputBaseFilename=Setup
Compression=lzma
SolidCompression=yes
PrivilegesRequired=admin
DisableProgramGroupPage=yes

[Files]
Source: "dist\programa.exe"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{group}\Vardenis-Pavardenis"; Filename: "{app}\programa.exe"; WorkingDir: "{app}"
Name: "{userdesktop}\Vardenis-Pavardenis"; Filename: "{app}\programa.exe"; WorkingDir: "{app}"

[Registry]
Root: HKLM; Subkey: "Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers"; ValueType: string; ValueName: "{app}\programa.exe"; ValueData: "RUNASADMIN"; Flags: uninsdeletevalue

[Run]
Filename: "{app}\programa.exe"; Description: "Paleisti Vardenis-Pavardenis"; Flags: nowait postinstall skipifsilent