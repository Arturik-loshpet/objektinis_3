; Inno Setup scriptas Windows installer failui.
; Sis failas turi buti pagrindiniame projekto aplanke.
; Pries Compile programa turi buti: dist\programa.exe

[Setup]
AppId={{A4E7C0A6-1F15-4F46-8E62-36A6247B77E4}
AppName=Artur-Vascuk
AppVersion=1.0
AppPublisher=VU
DefaultDirName={pf}\VU\Artur-Vascuk
DefaultGroupName=VU\Artur-Vascuk
OutputDir=installer
OutputBaseFilename=Setup
Compression=lzma
SolidCompression=yes
PrivilegesRequired=admin
DisableProgramGroupPage=yes

[Files]
Source: "dist\programa.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "dist\libgcc_s_seh-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dist\libstdc++-6.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dist\libwinpthread-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dist\studentai10000.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "dist\studentai100000.txt"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{group}\Artur-Vascuk"; Filename: "{app}\programa.exe"; WorkingDir: "{app}"
Name: "{userdesktop}\Artur-Vascuk"; Filename: "{app}\programa.exe"; WorkingDir: "{app}"

[Registry]
Root: HKLM; Subkey: "Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers"; ValueType: string; ValueName: "{app}\programa.exe"; ValueData: "RUNASADMIN"; Flags: uninsdeletevalue

[Run]
Filename: "{app}\programa.exe"; Description: "Paleisti Artur-Vascuk"; Flags: nowait postinstall skipifsilent
