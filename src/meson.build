src_inc = include_directories('.')

yaml_inc = [
    power_status_hpp
]

yaml_src = [
    power_status_cpp
]

executable(
    'helloworld',
    'helloworld.cpp',
    'utils.cpp',
    yaml_inc,
    yaml_src,
    include_directories: [src_inc, hello_inc],
    dependencies: [
        sdbusplus_dep
    ],
    install: true,
    install_dir: get_option('bindir')
)