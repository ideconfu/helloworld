power_status_hpp = custom_target(
    'server.hpp',
    capture: true,
    command: [
        sdbuspp,
        '-r', meson.project_source_root(),
        'interface',
        'server-header',
        'xyz.openbmc_project.Power.PowerStatus',
    ],
    input: '../PowerStatus.interface.yaml',
    install: true,
    install_dir: get_option('includedir') / 'xyz/openbmc_project/Power/PowerStatus/',
    output: 'server.hpp',
)

power_status_common_hpp = custom_target(
    'common.hpp',
    capture: true,
    command: [
        sdbuspp,
        '-r', meson.project_source_root(),
        'interface',
        'common-header',
        'xyz.openbmc_project.Power.PowerStatus',
    ],
    input: '../PowerStatus.interface.yaml',
    install: true,
    install_dir: get_option('includedir') / 'xyz/openbmc_project/Power/PowerStatus/',
    output: 'common.hpp',
)

power_status_cpp = custom_target(
    'server.cpp',
    capture: true,
    command: [
        sdbuspp,
        '-r', meson.project_source_root(),
        'interface',
        'server-cpp',
        'xyz.openbmc_project.Power.PowerStatus',
    ],
    input: '../PowerStatus.interface.yaml',
    output: 'server.cpp',
)