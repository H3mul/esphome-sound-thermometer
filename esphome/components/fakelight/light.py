import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import light

fakelight_ns = cg.esphome_ns.namespace('fakelight')
FakeLightOutput = fakelight_ns.class_('FakeLightOutput', cg.Component, light.LightOutput)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(FakeLightOutput),
}).extend(light.RGB_LIGHT_SCHEMA)

async def to_code(config):
    var = cg.new_Pvariable(config[cv.GenerateID()])
    await cg.register_component(var, config)
    