project(
  'nic-manager',
  'cpp',
  default_options: [
    'warning_level=3',
    'werror=true',
    'cpp_std=c++20',
    'prefix=/usr/local'
    ],
  license: 'Apache-2.0',
  version: '1.0',
  meson_version: '>=0.58.0',
  )

sdbusplus_dep = dependency('sdbusplus')
sdbuspp = find_program('sdbus++')

hello_inc = include_directories('.')

subdir('xyz/openbmc_project/Power/PowerStatus')
subdir('src')
subdir('services')