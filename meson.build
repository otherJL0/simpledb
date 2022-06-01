project('simpledb', 'c',
  version : '0.1',
  default_options : [
    'warning_level=3',
    'werror=true',
    'c_std=c17'
    ])

add_project_arguments('-pedantic',
                      '-pedantic-errors',
                      '-ftrapv',
                      '-save-stats',
                      '-ftime-report',
                      language : 'c')

exe = executable('simpledb', 'src/main.c',
  install : true)

test('basic', exe)
