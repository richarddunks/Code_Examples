def test_nested(klass, attributes = {})
  setup do
    @entry = entries(:valid)
    klass.delete_all # remove fixtures
    @entry.send(attrize(klass)).build(attributes).save
  end

  test "should have all #{attrize(klass)} fields in form" do
    get :new
    accessible_attrs(klass).each do |f|
      assert_select "fieldset.#{attrize(klass).singularize}"
    end
  end

  test "should create entry with #{attrize(klass)}" do
    assert_difference("#{klass}.count", 1) do
      e = Entry.new(first_name: 'foo', last_name: 'bar')
      e.send(attrize(klass)).build(attributes).save
    end
  end

  test "should show #{attrize(klass)} entry" do
    get :show, id: @entry
    assert_select "div.#{attrize(klass)}", true
  end
 
  test "should destroy #{attrize(klass)}" do
    assert_difference("#{klass}.count", -1) do
      put :update, id: @entry, entry: {
        "#{attrize(klass, -1)}" => {0 => {
            _destroy: 1, id: @entry.send(attrize(klass)).first.id }}
      }
    end
    assert_redirected_to entry_path(@entry)
  end
end

def attrize(klass, index=nil, field=nil)
    s = klass.name.tableize
    return s unless index

    s << "_attributes"
    return s if index < 0

    "#entry_%s_%s_%s" % [s, index, field]
  end
