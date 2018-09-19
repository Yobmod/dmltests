import json
import requests
from flask_babel import _
from app import app


def translate(text: str, source_language: str, dest_language: str) -> str:
    trans_or_error: str
    if 'MS_TRANSLATOR_KEY' not in app.config or not app.config['MS_TRANSLATOR_KEY']:
        trans_or_error = _('Error: the translation service is not configured.')
        return trans_or_error
    else:
        auth = {'Ocp-Apim-Subscription-Key': app.config['MS_TRANSLATOR_KEY']}

    r = requests.get('https://api.microsofttranslator.com/v2/Ajax.svc'
                     '/Translate?text={}&from={}&to={}'.format(
                         text, source_language, dest_language), headers=auth)
    if r.status_code != 200:
        # log(r.status_code)
        return trans_or_error

    try:
        trans = json.loads(r.content.decode('utf-8-sig'))
        if isinstance(trans, str):
            trans_or_error = trans
    except Exception as e:
        # log(e)
        trans_or_error = _('Error: the translation service failed.')
    finally:
        return trans_or_error
