unit_files = [
    'helloworld.service',
]

systemd = dependency('systemd')
servicedir = systemd.get_variable('systemdsystemunitdir')

foreach unit : unit_files
configure_file(input: unit,
               output: unit,
               copy: true,
               install_dir: servicedir)
endforeach