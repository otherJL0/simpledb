project('simpledb', 'c',
  version : '0.1',
  default_options : [
    'warning_level=3',
    'werror=true',
    ])

add_project_arguments('-pedantic',
                      '-pedantic-errors',
                      '-std=c17',
                      '-march=znver3',
                      '-ftrapv',
                      '-save-stats',
                      '-ftime-report',
                      language : 'c')

exe = executable('simpledb', 'src/main.c',
  install : true)

test('basic', exe)
