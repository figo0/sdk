// Copyright (c) 2013, the Dart project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

import 'dart:html';

import 'package:expect/minitest.dart';

main() {
  group('supported', () {
    test('supported', () {
      expect(SpeechRecognition.supported, true);
    });
  });

  group('types', () {
    var expectation = SpeechRecognition.supported ? returnsNormally : throws;

    test('SpeechRecognition', () {
      expect(() {
        new SpeechRecognition();
      }, expectation);
    });
/*
    https://code.google.com/p/dart/issues/detail?id=11825
    test('SpeechRecognitionEvent', () {
      expect(() {
        var e = new Event.eventType('SpeechRecognitionEvent', 'speech');
        expect(e is SpeechRecognitionEvent, true);
      }, expectation);
    });
*/
    test('SpeechRecognitionError', () {
      expect(() {
        var e = new Event.eventType('SpeechRecognitionError', 'speech');
        expect(e is SpeechRecognitionError, true);
      }, expectation);
    });
  });
}

