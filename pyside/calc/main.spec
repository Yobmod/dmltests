# -*- mode: python ; coding: utf-8 -*-

import PyInstaller.config
# PyInstaller.config.CONF['distpath'] = ".\\dist"
# PyInstaller.config.CONF['workpath'] = ".\\build"
# PyInstaller.config.CONF['upx_dir'] = "..\\..." 

block_cipher = None

a = Analysis(['main.py'],
             pathex=['c:\\dev\\dmltests\\pyside\\calc'],
             binaries=[],
             datas=[   # tuple[filename, pathwithfilename]
                #('.\settings.json', '.'),
                ('coffeebean.ico', '.'),
             ],
             hiddenimports=[],
             hookspath=[],
             runtime_hooks=[],
             excludes=[],
             win_no_prefer_redirects=False,
             win_private_assemblies=False,
             cipher=block_cipher,
             noarchive=False)
pyz = PYZ(a.pure, a.zipped_data,
             cipher=block_cipher)
exe = EXE(pyz,
          a.scripts,
          [],
          exclude_binaries=True,
          name='main',
          debug=False,
          bootloader_ignore_signals=False,
          strip=False,
          upx=True,
          console=True,
            icon='.\\coffeebean.ico'
            )
coll = COLLECT(exe,
               a.binaries,
               a.zipfiles,
               a.datas,
               strip=False,
               upx=True,
               upx_exclude=[],
               name='main')

print("\nZipping files...")
import os
import shutil
import pathlib


working_dir = os.getcwd()
working_dir = pathlib.Path(working_dir)
# working_dir = working_dir.parents[0]  # parent[0] = pyside
dest_path = f"{working_dir}/dist/main"
zip_source_path = f"{working_dir}/dist/main"

shutil.make_archive(dest_path, 'zip', zip_source_path)

print(".... done")