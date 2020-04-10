#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>

static const unsigned char qt_resource_tree[] = {
0,
0,0,0,0,2,0,0,0,7,0,0,0,1,0,0,0,
8,0,0,0,0,0,1,0,0,0,0,0,0,0,244,0,
0,0,0,0,1,0,0,0,0,0,0,0,150,0,0,0,
0,0,1,0,0,0,0,0,0,1,36,0,0,0,0,0,
1,0,0,0,0,0,0,0,192,0,0,0,0,0,1,0,
0,0,0,0,0,0,42,0,0,0,0,0,1,0,0,0,
0,0,0,0,100,0,0,0,0,0,1,0,0,0,0};
static const unsigned char qt_resource_names[] = {
0,
1,0,0,0,47,0,47,0,14,0,249,19,220,0,83,0,
105,0,109,0,117,0,108,0,97,0,116,0,105,0,111,0,
110,0,46,0,113,0,109,0,108,0,26,9,174,38,252,0,
67,0,117,0,115,0,116,0,111,0,109,0,105,0,122,0,
105,0,110,0,103,0,82,0,97,0,100,0,105,0,111,0,
66,0,117,0,116,0,116,0,111,0,110,0,46,0,113,0,
109,0,108,0,22,13,74,171,60,0,67,0,117,0,115,0,
116,0,111,0,109,0,105,0,122,0,105,0,110,0,103,0,
83,0,112,0,105,0,110,0,66,0,111,0,120,0,46,0,
113,0,109,0,108,0,18,3,197,216,252,0,109,0,97,0,
105,0,110,0,95,0,105,0,110,0,116,0,101,0,114,0,
102,0,97,0,99,0,101,0,46,0,113,0,109,0,108,0,
23,5,245,82,220,0,67,0,117,0,115,0,116,0,111,0,
109,0,105,0,122,0,105,0,110,0,103,0,67,0,111,0,
109,0,98,0,111,0,66,0,111,0,120,0,46,0,113,0,
109,0,108,0,21,1,45,63,60,0,67,0,117,0,115,0,
116,0,111,0,109,0,105,0,122,0,105,0,110,0,103,0,
66,0,117,0,116,0,116,0,111,0,110,0,46,0,113,0,
109,0,108,0,18,4,12,196,188,0,109,0,97,0,105,0,
110,0,95,0,115,0,105,0,109,0,117,0,108,0,97,0,
116,0,111,0,114,0,46,0,113,0,109,0,108};
static const unsigned char qt_resource_empty_payout[] = { 0, 0, 0, 0, 0 };
QT_BEGIN_NAMESPACE
extern Q_CORE_EXPORT bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
QT_END_NAMESPACE
namespace QmlCacheGeneratedCode {
namespace _0x5f__main_simulator_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__CustomizingButton_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__CustomizingComboBox_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__main_interface_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__CustomizingSpinBox_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__CustomizingRadioButton_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__Simulation_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    ~Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
        resourcePathToCachedUnit.insert(QStringLiteral("/main_simulator.qml"), &QmlCacheGeneratedCode::_0x5f__main_simulator_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/CustomizingButton.qml"), &QmlCacheGeneratedCode::_0x5f__CustomizingButton_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/CustomizingComboBox.qml"), &QmlCacheGeneratedCode::_0x5f__CustomizingComboBox_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/main_interface.qml"), &QmlCacheGeneratedCode::_0x5f__main_interface_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/CustomizingSpinBox.qml"), &QmlCacheGeneratedCode::_0x5f__CustomizingSpinBox_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/CustomizingRadioButton.qml"), &QmlCacheGeneratedCode::_0x5f__CustomizingRadioButton_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Simulation.qml"), &QmlCacheGeneratedCode::_0x5f__Simulation_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.version = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
QT_PREPEND_NAMESPACE(qRegisterResourceData)(/*version*/0x01, qt_resource_tree, qt_resource_names, qt_resource_empty_payout);
}

Registry::~Registry() {
    QQmlPrivate::qmlunregister(QQmlPrivate::QmlUnitCacheHookRegistration, quintptr(&lookupCachedUnit));
}

const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qml)() {
    ::unitRegistry();
    Q_INIT_RESOURCE(qml_qmlcache);
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qml))
int QT_MANGLE_NAMESPACE(qCleanupResources_qml)() {
    Q_CLEANUP_RESOURCE(qml_qmlcache);
    return 1;
}
