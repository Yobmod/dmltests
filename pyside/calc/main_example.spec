# -*- mode: python -*-
import PyInstaller.config
PyInstaller.config.CONF['distpath'] = ".\\dist"
# PyInstaller.config.CONF['workpath'] = ".\\build  ##  to python?" 
# PyInstaller.config.CONF['upx_dir'] = "..\\..." 

block_cipher = None


a = Analysis(['main.py'],
             pathex=['C:\\dev\\dmltests\\pyside\\calc'],
             binaries=[],
             datas=[   # tuple[filename, pathwithfilename]
                #('.\default_settings.json', '.'),
                #('.\settings.json', '.'),
                ('coffeebean.ico', '.'),
             ],
             hiddenimports=[],
             hookspath=[],
             runtime_hooks=[],
             excludes=[],
             win_no_prefer_redirects=False,
             win_private_assemblies=False,
             cipher=block_cipher)
pyz = PYZ(a.pure, a.zipped_data,
             cipher=block_cipher)
exe = EXE(pyz,
          a.scripts,
          exclude_binaries=True,
          name='main',
          debug=False,
          strip=False,
          upx=False,
          console=True,
          icon='.\\coffeebean.ico' )
coll = COLLECT(exe,
               a.binaries,
               a.zipfiles,
               a.datas,
               strip=False,
               upx=True,
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