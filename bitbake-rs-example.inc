DEPENDS += "openssl"

export OPENSSL_DIR = "${STAGING_EXECPREFIXDIR}"


SYSTEMD_AUTO_ENABLE = "enable"
SYSTEMD_SERVICE_\${PN} = "ipinfo.service"

do_install () {
    install -d  ${D}${bindir}
    install -m 755 ${WORKDIR}/target/${CARGO_TARGET_SUBDIR}/bitbake-rs-example ${D}/${bindir}/bitbake-rs-example"
		install -m 644 ${WORKDIR}/ipinfo.service ${D}/${systemd_unitdir}/system
}
