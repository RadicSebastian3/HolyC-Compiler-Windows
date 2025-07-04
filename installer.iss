; HolyC Compiler Windows Installer Script
[Setup]
AppName=HolyC Compiler
AppVersion=1.0
DefaultDirName={pf}\HolyC
DefaultGroupName=HolyC
Compression=lzma
OutputDir=installer
OutputBaseFilename=HolyC-Compiler-Setup

[Files]
Source: "build\Release\hcc.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "src\holyc.h"; DestDir: "{app}\include"; Flags: ignoreversion

[Icons]
Name: "{group}\HolyC Compiler"; Filename: "{app}\hcc.exe"

[Registry]
Root: HKLM; Subkey: "SYSTEM\CurrentControlSet\Control\Session Manager\Environment"; \
    ValueType: string; ValueName: "HCC_PATH"; ValueData: "{app}"; Flags: preservestringtype

[Run]
Filename: "{app}\hcc.exe"; Description: "Run HolyC Compiler"; Flags: postinstall nowait

[Code]
procedure CurStepChanged(CurStep: TSetupStep);
begin
  if CurStep = ssPostInstall then
  begin
    // Update PATH environment variable
    Exec('cmd.exe', '/c setx PATH "%PATH%;{app}"', '', SW_HIDE, ewWaitUntilTerminated, ResultCode);
  end;
end;