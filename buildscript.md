cmake 신텍스 거지같아서 최후의 수단
 - https://en.sfml-dev.org/forums/index.php?topic=27336.0
 
https://premake.github.io/docs/Your-First-Script
https://github.com/bkaradzic/GENie
https://github.com/build2/build2


## meason 설치 (Windows)

- ref: <https://mesonbuild.com/SimpleStart.html>
- 설치 순서
  - [visualstudio](https://visualstudio.microsoft.com/)
    - Desktop development with C++.
  - [github: meson release](https://github.com/mesonbuild/meson/releases)
    - `C:\Program Files\Meson` 에 `meson.exe`, `ninja.exe`
    - 재부팅 후 콘솔에서 확인

    ``` cmd
    meason --version
    ninja --version
    ```

## 실행

- Developer Command Prompt for VS 2019

``` cmd
mkdir SampleProject
cd SampleProject
meson builddir --backend vs                # 백엔드를 visual studio로
meson builddir --backend vs --reconfigure  # 재설정
meson compile -C builddir                  # ninja -C builddir
```

- [include_directories](https://mesonbuild.com/Include-directories.html)
- [Why must all subprojects be inside a single directory?](https://mesonbuild.com/Subprojects.html#why-must-all-subprojects-be-inside-a-single-directory)
- [Why can't I specify target files with a wildcard?](https://mesonbuild.com/FAQ.html#why-cant-i-specify-target-files-with-a-wildcard)

``` txt
// https://mesonbuild.com/Comparisons.html#cons4

Relatively new so it does not have a large user base yet, and may thus contain some unknown bugs. Visual Studio and XCode backends not as high quality as Ninja one.
```
