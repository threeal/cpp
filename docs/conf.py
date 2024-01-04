import os, subprocess

project = 'Errors C++'
author = 'Alfi Maulana'
copyright = '2023-2024, Alfi Maulana'

extensions = ['breathe']

subprocess.call('cmake .. -B ../build -D BUILD_DOCS=ON', shell=True)
subprocess.call('cmake --build ../build --target errors_docs --target errors_format_docs', shell=True)

breathe_projects = {
    "errors": "../build/errors_docs",
    "errors_format": "../build/components/format/errors_format_docs"
}

html_theme = 'furo'
html_static_path = ['_static']
