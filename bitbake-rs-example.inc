DEPENDS += "openssl"

export OPENSSL_DIR = "${STAGING_EXECPREFIXDIR}"

inherit systemd

SYSTEMD_AUTO_ENABLE = "enable"
SYSTEMD_SERVICE_${PN} = "ipinfo.service"

do_install () {
    install -d ${D}${bindir}
    install -m 755 ${S}/target/${CARGO_TARGET_SUBDIR}/bitbake-rs-example ${D}${bindir}/bitbake-rs-example
		install -d ${D}${systemd_unitdir}/system
		install -m 644 ${S}/ipinfo.service ${D}${systemd_unitdir}/system
}
